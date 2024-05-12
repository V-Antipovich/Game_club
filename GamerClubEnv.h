#pragma once

#include <deque>
#include <queue>
#include <set>
//#include <unordered_set>
#include "ClientsBase.h"
#include "Table.h"
#include "Event.h"
#include <iostream>
#include <functional>
#include <algorithm>
class GamerClubEnv: public ClientsBase {
    typedef void (GamerClubEnv::*MemberFunPointer)(Event*);
    const int64_t ClientCameActionCode=1;
    const int64_t ClientSatActionCode=2;
    const int64_t ClientWaitingActionCode=3;
    const int64_t ClientGoneActionCode=4;
    int64_t OutputClientGoneActionCode = 11;
    const int64_t OutputClientSatActionCode=12;
    const int64_t ErrorActionCode=13;
    std::string YouShallNotPassError = "YouShallNotPass";
    std::string NotOpenYetError = "NotOpenYet";
    std::string PlaceIsBusyError = "PlaceIsBusy";
    std::string ClientUnknownError = "ClientUnknown";
    std::string ICanWaitNoLongerError = "ICanWaitNoLonger";

    int64_t numTables = 0;
    int64_t costPerHour = 0;
    TimeStamp startWorkTime;
    TimeStamp endWorkTime;
    std::queue<Event*> inputQueue;
    std::queue<Event*> outputQueue;

    void ClientCameAction(Event* event);
    void ClientSatAction(Event* event);
    void ClientWaitingAction(Event* event);
    void ClientGoneAction(Event* event);

    std::unordered_map<int64_t, MemberFunPointer> actionsMap;

    bool IsClosed(TimeStamp& tm);
    std::vector<int64_t> waitingGuests;
    std::map<int64_t, Table> tables;
    std::set<int64_t> free_tables;

    void RemoveFromQueue(int64_t clientId);

public:
    GamerClubEnv(int64_t numTables, int64_t costPerHour, TimeStamp &startWorkTime, TimeStamp &endWorkTime, std::queue<Event*>& inputQueue);

    void HandleInputEvents();

    void Print();
};
