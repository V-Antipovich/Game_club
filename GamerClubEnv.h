#pragma once

#include <deque>
#include <queue>
#include <set>
#include "ClientsBase.h"
#include "Table.h"

class GamerClubEnv: public ClientsBase {
private:
    // O(1) на посадку следующего в очереди
    // O(n) (n/2) на удаление из середины очереди (при событии 3)


    int64_t numTables = 0;
    int64_t costPerHour = 0;
    TimeStamp startWorkTime;
    TimeStamp endWorkTime;
public:
    std::deque<int64_t> waitingGuests;
    std::map<int64_t, Table> tables;
    std::set<int64_t> free_tables;

    [[nodiscard]] int64_t GetNumTables() const;

    [[nodiscard]] int64_t GetCostPerHour() const;

    TimeStamp GetStartWorkTime();

    TimeStamp GetEndWorkTime();

    bool IsClosed(TimeStamp& tm);

    GamerClubEnv(int64_t numTables, int64_t costPerHour, TimeStamp &startWorkTime, TimeStamp &endWorkTime);
//        void HandleInputEvents();
    // TODO: пусть workflow будет извне ENV, а этот класс будет лишь функционалом для этих действий
    // TODO: Очистка очереди input: вынести логику из main ????сюда???
    // TODO: завершение дня: всех выгоняем и продолжаем набивать очередь на выход
    // TODO: вывод в терминал итоговой очереди
};
