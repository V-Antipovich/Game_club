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

