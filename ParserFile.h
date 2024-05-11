#pragma once
// TODO: выбросить то что уже было подключено
#include <string>
#include <cstdint>
#include <fstream>
#include "ParserFileError.h"
#include <sstream>
#include <iomanip>
#include <queue>
#include <unordered_set>
#include "Events/EventsFactory.h"
class ParserFile {
    private:
        const std::string nameKey = "name";
        const std::string tableNumKey = "tableNum";
        const std::unordered_set<int64_t> allowed_codes{1, 2, 3, 4};
        int64_t tablesNum=0;
        int64_t costPerHour=0;
        TimeStamp startWorkTime;
        TimeStamp endWorkTime;

        std::queue<BaseEvent*> inputEventsQueue;

    static bool is_time_valid(std::string &timestamp);

    bool is_code_valid(int64_t code);

    public:
        explicit ParserFile(std::string& path);

        std::queue<BaseEvent*> GetInputEventsQueue() const;
};
