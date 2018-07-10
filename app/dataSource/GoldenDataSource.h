#pragma once

#include "IDataSource.h"


#include "goldenapi.h"
#include <QSettings>

class GoldenDataSource : public IDataSource
{
public:
    GoldenDataSource();

    ///
    virtual int init(const char* config) override;
    virtual int start() override;
    virtual int stop() override;

private:
    /// according to the SDK manual, callback handler must own special socket which not allowed using for other purpose
    golden_int32 apiHandle;
    golden_int32 cbTagsHandle;
    golden_int32 cbSnapHandle;
    gob_tags_change_event_ex tagsCallback;
    gos_snaps_event_ex snapsCallback;
    goh_data_playback_ex hisCallback;

    QSettings* conf;

};

