#include "GoldenDataSource.h"

#include <QDebug>

golden_error on_tags_change (golden_int32 count, const golden_int32 *ids, golden_int32 what)
{
    return  GoldenDataSource::getInstance()->on_tags_changed(count, ids, what);
}

golden_error on_data_change (golden_int32 count,
                              const golden_int32 *ids,
                              const golden_int32 *datetimes,
                              const golden_int16 *ms,
                              const golden_float64 *values,
                              const golden_int64 *states,
                              const golden_int16 *qualities,
                              const golden_error *errors)
{
    return GoldenDataSource::getInstance()->on_data_changed(count, ids, datetimes, ms, values, states, qualities, errors);
}

GoldenDataSource* GoldenDataSource::instance = nullptr;

GoldenDataSource::GoldenDataSource(Canvas* canvas)
{
    apiHandle = 0;
    cbTagsHandle = 0;
    cbSnapHandle = 0;
    tagsCallback = nullptr;
    snapsCallback = nullptr;

    this->canvas = canvas;

    if (!instance) instance = this;
}

GoldenDataSource *GoldenDataSource::getInstance()
{
    return instance;
}

int GoldenDataSource::init(const char *config)
{
    if (conf) {
        qDebug() << "already inited!" ;
        return 0;
    }
    conf = new QSettings(config, QSettings::IniFormat);
    if (!conf->contains("/golden/server")) {
        qDebug() << "file: " << config << " not contains[/golden/server]";
        return -1;
    }
    if (!conf->contains("/golden/port")) {
        qDebug() << "file: " << config << " not contains[/golden/port]";
        return -1;
    }
    return 0;
}

int GoldenDataSource::start()
{
    if (!conf) {
        qDebug() << "not inited!" ;
        return -1;
    }
    QString host = conf->value("/golden/server").toString();
    int port = conf->value("/golden/port").toInt();
    golden_error ret = go_connect(host.toStdString().c_str(), port, &apiHandle);
    if (ret != GoE_OK) {
        qDebug() << "connect to host[" << host << "], port[" << port << "] failed! error_code[" << ret << "]";
        return ret;
    }

    ///
    ret = go_connect(host.toStdString().c_str(), port, &cbTagsHandle);
    if (ret != GoE_OK) {
        qDebug() << "connect to host[" << host << "], port[" << port << "] failed! error_code[" << ret << "]";
        return ret;
    }

    ret = go_connect(host.toStdString().c_str(), port, &cbSnapHandle);
    if (ret != GoE_OK) {
        qDebug() << "connect to host[" << host << "], port[" << port << "] failed! error_code[" << ret << "]";
        return ret;
    }

    return 0;
}

int GoldenDataSource::stop()
{
    if (cbTagsHandle) {
        gob_cancel_subscribe_tags (cbTagsHandle);
        go_disconnect(cbTagsHandle);
        cbTagsHandle = 0;
    }
    if (cbSnapHandle) {
        gos_cancel_subscribe_snapshots (cbSnapHandle);
        go_disconnect(cbSnapHandle);
        cbSnapHandle = 0;
    }
    if (apiHandle) {
        go_disconnect(apiHandle);
        apiHandle = 0;
    }
    return 0;
}

int GoldenDataSource::on_tags_changed(golden_int32 count, const golden_int32 *ids, golden_int32 what)
{
    return 0;
}

int GoldenDataSource::on_data_changed(golden_int32 count,
                                      const golden_int32 *ids,
                                      const golden_int32 *datetimes,
                                      const golden_int16 *ms,
                                      const golden_float64 *values,
                                      const golden_int64 *states,
                                      const golden_int16 *qualities,
                                      const golden_error *errors)
{
    return 0;
}

int GoldenDataSource::subscribe(golden_int32 count, const golden_int32 *ids, int type)
{
    golden_error *errors = new golden_error[count];
    if (type == S_Snapshot) gos_subscribe_snapshots(cbSnapHandle,  &count, ids, on_data_change, errors);
    else if (type == S_Tag) gob_subscribe_tags(cbTagsHandle, on_tags_change);
    delete[] errors;
    return 0;
}

int GoldenDataSource::cancel_subscribe(int type)
{
    if (type == S_Snapshot) gos_cancel_subscribe_snapshots (cbSnapHandle);
    else if (type == S_Tag) gob_cancel_subscribe_tags (cbTagsHandle);
    return 0;
}

GOLDEN_POINT *GoldenDataSource::getPointById(golden_int32 id)
{
    if (points.contains(id)) return std::get<0>(points[id]);
    ///
    GOLDEN_POINT *point = new  GOLDEN_POINT();
    point->id = id;
    GOLDEN_SCAN_POINT* scan = new GOLDEN_SCAN_POINT();
    GOLDEN_CALC_POINT* calc = new GOLDEN_CALC_POINT();
    golden_error err;
    golden_error ret = gob_get_points_property(apiHandle, 1, point, scan, calc, &err);
    if (ret == GoE_OK) {
        points[id] = std::make_tuple(point, scan, calc);
        return point;
    } else {
        return nullptr;
    }
}
