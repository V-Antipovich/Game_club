#include "Table.h"

void Table::UpdateTimeBusy(){
    totalBusy.hours = totalMinutesBusy/60;
    totalBusy.minutes = totalMinutesBusy%60;
}

void Table::UpdateTotalIncome(int64_t pricing) {
    totalIncome += pricing * totalBusy.hours;
    if (totalBusy.minutes > 0) {
        totalIncome += pricing;
    }
}

void Table::UpdateTotal(int64_t pricing) {
    UpdateTimeBusy();
    UpdateTotalIncome(pricing);
}

void Table::StartSession(int64_t clientID, TimeStamp &timeStamp) {
    is_empty = false;
    IDCurrentClient = clientID;
//    TableInterval newInterval(clientID, timeStamp);
    intervals.emplace_back(clientID, timeStamp);
//    intervals.emplace_back(newInterval);
}

void Table::CloseSession(TimeStamp &timeStamp, int64_t pricing) {
    intervals.back().CloseInterval(timeStamp, pricing);
    totalMinutesBusy += intervals.back().minutesSpent;
}

//void Table::CloseSession(int64_t clientId, TimeStamp &timeStamp) {
//    intervals.back().CloseInterval(timeStamp);
//}

