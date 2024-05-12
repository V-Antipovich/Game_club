#pragma once
#include <cstdint>
#include <vector>
#include "TableInterval.h"

class Table {
    private:
        void UpdateTimeBusy();
        void UpdateTotalIncome(int64_t pricing);
        std::vector<TableInterval> intervals;
    public:
        bool is_empty= true;
        int64_t IDCurrentClient=-1;
        int64_t totalMinutesBusy=0;
        TimeStamp totalBusy;
        int64_t totalIncome=0;

        void UpdateTotal(int64_t pricing);
        void StartSession(int64_t clientID, TimeStamp& timeStamp);
        void CloseSession(TimeStamp& timeStamp, int64_t pricing);
        Table()=default;
};
