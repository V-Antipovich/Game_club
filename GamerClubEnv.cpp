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

bool GamerClubEnv::IsClosed(TimeStamp& tm) {
    return tm < startWorkTime || tm > endWorkTime;
}

void GamerClubEnv::ClientCameAction(Event *event) {
    int64_t id = AddIfNew(event->clientName);

    if (IsPresent(id)) {
        auto *err = new Event(event->timeStamp, ErrorActionCode, YouShallNotPassError, true);
        outputQueue.push(err);
        return;
    }
    if (IsClosed(event->timeStamp)) {
        auto *err = new Event(event->timeStamp, ErrorActionCode, NotOpenYetError, true);
        outputQueue.push(err);
        return;
    }
    waitingGuests.push_back(id);
}

void GamerClubEnv::ClientSatAction(Event *event) {
    // TODO: implement normally
    std::cout<<"ClietnSatAction playing\n";
}

void GamerClubEnv::ClientWaitingAction(Event *event) {
    // TODO: implement normally
    std::cout<<"ClientWaitingAction playing\n";
}

void GamerClubEnv::ClientGoneAction(Event *event) {
    // TODO: implement normally
    std::cout<<"ClientGoneAction playing\n";
}

void GamerClubEnv::ErrorAction(Event*event) {
    // TODO: implement normally
    std::cout<<"ErrorAction playing\n";
}

GamerClubEnv::GamerClubEnv(int64_t numTables, int64_t costPerHour, TimeStamp &startWorkTime, TimeStamp &endWorkTime, std::queue<Event*>& inputQueue)
        : numTables(numTables), costPerHour(costPerHour), startWorkTime(startWorkTime), endWorkTime(endWorkTime), inputQueue(inputQueue) {
    for (int64_t i = 1; i <= numTables; ++i) {
        tables[i];
        free_tables.insert(i);
    }
    actionsMap.insert(std::make_pair(ClientCameActionCode, &GamerClubEnv::ClientCameAction));
    actionsMap.insert(std::make_pair(ClientSatActionCode, &GamerClubEnv::ClientSatAction));
    actionsMap.insert(std::make_pair(ClientWaitingActionCode, &GamerClubEnv::ClientWaitingAction));
    actionsMap.insert(std::make_pair(ClientGoneActionCode, &GamerClubEnv::ClientGoneAction));
    actionsMap.insert(std::make_pair(ErrorActionCode, &GamerClubEnv::ErrorAction));
}

void GamerClubEnv::HandleInputEvents() {
    Event* event = nullptr;
    while (!inputQueue.empty()) {
        event = inputQueue.front();
        inputQueue.pop();
        outputQueue.push(event);
        MemberFunPointer mfp = actionsMap[event->ID];
        (this->*mfp)(event);
    }
    // TODO: конец дня всех выгнать и оставшиеся события напихать в очередь
}

void GamerClubEnv::Print() {
    Event* event = nullptr;
    std::cout<<startWorkTime.PrintTime()<<"\n";
    while (!outputQueue.empty()) {
        event = outputQueue.front();
        outputQueue.pop();
        std::cout<<event->to_str()<<"\n";
    }
    std::cout<<endWorkTime.PrintTime()<<"\n";
    // TODO: cout выручка
}