#include "GamerClubEnv.h"



int64_t GamerClubEnv::GetNumTables() const {
    return numTables;
}

int64_t GamerClubEnv::GetCostPerHour() const {
    return costPerHour;
}

TimeStamp GamerClubEnv::GetStartWorkTime() {
    return startWorkTime;
}

TimeStamp GamerClubEnv::GetEndWorkTime() {
    return endWorkTime;
}

//void GamerClubEnv::HandleInputEvents() {
//    while (!inputEventsQueue.empty()) {
//        auto inputEvent = inputEventsQueue.front();
//        inputEventsQueue.pop();
//        outputEventsQueue.push(inputEvent);
//        inputEvent->Act(this);
//    }
//}
GamerClubEnv::GamerClubEnv(int64_t numTables, int64_t costPerHour, TimeStamp &startWorkTime, TimeStamp &endWorkTime)
        : numTables(numTables), costPerHour(costPerHour), startWorkTime(startWorkTime), endWorkTime(endWorkTime) {
    for (int64_t i = 1; i <= numTables; ++i) {
        tables[i];
        free_tables.insert(i);
    }
}

bool GamerClubEnv::IsClosed(TimeStamp& tm) {
    return tm < startWorkTime || tm > endWorkTime;
}
