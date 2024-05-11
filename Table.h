#pragma once
#include <cstdint>
#include <vector>
#include "TableInterval.h"

class Table {
    private:
        void UpdateTimeBusy();
        void UpdateTotalIncome(int64_t pricing);
    public:
        bool is_empty= true;
        int64_t IDCurrentClient=-1;
        int64_t totalMinutesBusy=0;
        TimeStamp totalBusy;
        int64_t totalIncome=0;
        std::vector<TableInterval> intervals;
        void UpdateTotal(int64_t pricing);
        Table()=default;
};
