#include "Table.h"

void Table::UpdateTimeBusy(){
    totalBusy.hours = totalMinutesBusy/60;
    totalBusy.minutes = totalMinutesBusy%60;
}

void Table::UpdateTotalIncome(int64_t pricing, int64_t minutes) {
    totalIncome += pricing * (minutes / 60);
    if (minutes % 60 > 0) {
        totalIncome += pricing;
    }
}

void Table::StartSession(int64_t clientID, TimeStamp &timeStamp) {
    is_empty = false;
    IDCurrentClient = clientID;
    intervals.emplace_back(clientID, timeStamp);
}

void Table::CloseSession(TimeStamp &timeStamp, int64_t pricing) {
    is_empty = true;
    intervals.back().CloseInterval(timeStamp, pricing);
    totalMinutesBusy += intervals.back().minutesSpent;
    UpdateTotalIncome(pricing, intervals.back().minutesSpent);
}
