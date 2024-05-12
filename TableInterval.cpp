#include "TableInterval.h"

void TableInterval::CountIncome(int64_t pricing) {
    int64_t int_hours = minutesSpent / 60;
    if (minutesSpent % 60 > 0) {
        ++int_hours;
    }
    income = pricing*int_hours;
}

TableInterval::TableInterval(int64_t clientID, TimeStamp &startTime): clientID(clientID), start(startTime) {}

void TableInterval::CloseInterval(TimeStamp &endTime, int64_t pricing) {
    finish = endTime;
    clientID = -1;
    is_interval_closed = true;
    minutesSpent = finish-start;
    CountIncome(pricing);
}

//TableInterval::TableInterval(TableInterval &&ti) noexcept : clientID(ti.clientID), income(ti.income), minutesSpent(ti.minutesSpent), start(std::move(ti.start)), finish(std::move(ti.finish)) , is_interval_closed(ti.is_interval_closed) {
//}

