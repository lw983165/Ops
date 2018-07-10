#include "GoldenDataSource.h"

#include <QDebug>

golden_error on_tags_change (golden_int32 count, const golden_int32 *ids, golden_int32 what)
{
    return  GoE_OK;
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
    return  GoE_OK;
}

GoldenDataSource::GoldenDataSource()
{
    apiHandle = 0;
    cbTagsHandle = 0;
    cbSnapHandle = 0;
    tagsCallback = nullptr;
    snapsCallback = nullptr;
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
