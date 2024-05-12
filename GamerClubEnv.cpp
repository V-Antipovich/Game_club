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
    if (waitingGuests.size() >= numTables) {
        auto *leaves = new Event(event->timeStamp, OutputClientGoneActionCode, event->clientName, false);
        outputQueue.push(leaves);
        return;
    }
    waitingGuests.push_back(id);
    ClientWaits(id, static_cast<int64_t>(waitingGuests.size()));
}

void GamerClubEnv::ClientSatAction(Event *event) {
    int64_t id = AddIfNew(event->clientName);
    if (!IsPresent(id)) {
        auto *err = new Event(event->timeStamp, ErrorActionCode, ClientUnknownError, true);
        outputQueue.push(err);
        return;
    }

    int64_t newTableNum = event->tableNum;
    // Если стол занят
    if (!tables[newTableNum].is_empty) {
        auto *err = new Event(event->timeStamp, ErrorActionCode, PlaceIsBusyError, true);
        outputQueue.push(err);
        return;
    }
    // Закрываем текущий столик, если есть
    int64_t oldTableNum = GetTableNumber(id);
    if (oldTableNum > 0) {
        tables[oldTableNum].CloseSession(event->timeStamp, costPerHour);
        free_tables.insert(oldTableNum);
    } else {
        // Если чел не за столом, тогда он в очереди - удалим его оттуда
        RemoveFromQueue(id);
        ClientLeaves(id);
    }
    // Открываем новый
    tables[newTableNum].StartSession(id, event->timeStamp);
    free_tables.erase(newTableNum);
    ClientSits(id, newTableNum);
}

void GamerClubEnv::ClientWaitingAction(Event *event) {
    // В клубе есть свободные столы
    int64_t id = AddIfNew(event->clientName);
    if (!free_tables.empty()) {
        auto *err = new Event(event->timeStamp, ErrorActionCode, ICanWaitNoLongerError, true);
        outputQueue.push(err);
        return;
    }
    if (numTables < waitingGuests.size()) {
        RemoveFromQueue(id);
        ClientLeaves(id);
        auto *leave = new Event(event->timeStamp, OutputClientGoneActionCode, event->clientName, false);
        outputQueue.push(leave);
    }
}

void GamerClubEnv::ClientGoneAction(Event *event) {
    int64_t id = AddIfNew(event->clientName);
    if (!IsPresent(id)) {
        auto *err = new Event(event->timeStamp, ErrorActionCode, ClientUnknownError, true);
        outputQueue.push(err);
        return;
    }
    if (IsWaiting(id)) {
        RemoveFromQueue(id);
        ClientLeaves(id);
    } else {
        int64_t tableNum = GetTableNumber(id);
        tables[tableNum].CloseSession(event->timeStamp, costPerHour);
        ClientLeaves(id);
        if (!waitingGuests.empty()) {
            int64_t newID = waitingGuests[0];
            std::string newName = GetName(newID);
            RemoveFromQueue(newID);
            auto *sits = new Event(event->timeStamp, OutputClientSatActionCode, newName, tableNum);
            outputQueue.push(sits);
        }
    }
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
//    actionsMap.insert(std::make_pair(ErrorActionCode, &GamerClubEnv::ErrorAction));
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
    std::cout<<"ВЫРУЧКА\n";
}

void GamerClubEnv::RemoveFromQueue(int64_t clientId) {
    waitingGuests.erase(std::remove(waitingGuests.begin(), waitingGuests.end(), clientId), waitingGuests.end());

}
