#pragma once

#include <deque>
#include <queue>
#include <set>
#include "ClientsBase.h"
#include "Table.h"
#include "Event.h"
#include <iostream>
#include <functional>
class GamerClubEnv: public ClientsBase {
    typedef void (GamerClubEnv::*MemberFunPointer)(Event*);

    // O(1) на посадку следующего в очереди
    // O(n) (n/2) на удаление из середины очереди (при событии 3)
    const int64_t ClientCameActionCode=1;
    const int64_t ClientSatActionCode=2;
    const int64_t ClientWaitingActionCode=3;
    const int64_t ClientGoneActionCode=4;
    const int64_t OutputClientGoneActionCode=11;
    const int64_t OutputClientSatActionCode=12;
    const int64_t ErrorActionCode=13;
    int64_t numTables = 0;
    int64_t costPerHour = 0;
    TimeStamp startWorkTime;
    TimeStamp endWorkTime;
    std::queue<Event*> inputQueue;
    std::queue<Event*> outputQueue;

    void ClientCameAction(Event*);
    void ClientSatAction(Event*);
    void ClientWaitingAction(Event*);
    void ClientGoneAction(Event*);
    void ErrorAction(Event*);

    std::unordered_map<int64_t, MemberFunPointer> actionsMap;

public:
    std::deque<int64_t> waitingGuests;
    std::map<int64_t, Table> tables;
    std::set<int64_t> free_tables;

    [[nodiscard]] int64_t GetNumTables() const;

    [[nodiscard]] int64_t GetCostPerHour() const;

    TimeStamp GetStartWorkTime();

    TimeStamp GetEndWorkTime();

    bool IsClosed(TimeStamp& tm);

    GamerClubEnv(int64_t numTables, int64_t costPerHour, TimeStamp &startWorkTime, TimeStamp &endWorkTime, std::queue<Event*>& inputQueue);
    void HandleInputEvents();

    void Print();
    // TODO: пусть workflow будет извне ENV, а этот класс будет лишь функционалом для этих действий
    // TODO: Очистка очереди input: вынести логику из main ????сюда???
    // TODO: завершение дня: всех выгоняем и продолжаем набивать очередь на выход
    // TODO: вывод в терминал итоговой очереди
};
