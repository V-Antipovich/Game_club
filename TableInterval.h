#pragma once
#include "TimeStamp.h"
class TableInterval {
    private:
//        void CountTime();
        void CountIncome(int64_t pricing);
    public:
        bool is_interval_closed= false;
        int64_t clientID=-1;
        int64_t income=0;
        int64_t minutesSpent=0;
        TimeStamp start;
        TimeStamp finish;

        TableInterval(int64_t clientID, TimeStamp& startTime);

        void CloseInterval(TimeStamp& endTime, int64_t pricing);
};
