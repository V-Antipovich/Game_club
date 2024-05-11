#pragma once
// TODO: выбросить то что уже было подключено
#include <string>
#include <cstdint>
#include <fstream>
#include "ParserFileError.h"
#include <sstream>
#include <iomanip>
#include <map>
#include <queue>
#include <vector>
#include <unordered_set>
#include "Events/EventsFactory.h"

// Будет парсить файл и хранить в себе структуры всего игрового клуба
class ParserFile {
    private:
        const std::string nameKey = "name";
        const std::string tableNumKey = "tableNum";
        const std::unordered_set<int64_t> allowed_codes{1, 2, 3, 4};
        static bool is_time_valid(std::string &timestamp);

        bool is_code_valid(int64_t code);

    public:
        explicit ParserFile(std::string& path);
        std::queue<BaseEvent*> inputEventsQueue;
        int64_t tablesNum=0;
        int64_t costPerHour=0;
        TimeStamp startWorkTime;
        TimeStamp endWorkTime;
};
