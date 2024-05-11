#pragma once
#include <string>
#include <cstdint>
#include <ctime>
#include <fstream>
#include "ParserFileError.h"
#include <sstream>
#include <iomanip>
#include <queue>
#include <unordered_set>
#include "Events/EventsFactory.h"
class ParserFile {
    private:
        const char *parseFormat = "%H:%M";
    const std::unordered_set<int64_t> allowed_codes{1, 2, 3, 4};
        int64_t tablesNum=0;
        int64_t costPerHour=0;
        std::tm startWorkTime;
        std::tm endWorkTime;
//        std::queue<BaseEvent*>
        std::queue<std::vector<std::string>> args;

    static bool is_time_valid(std::string &timestamp);

    bool is_code_valid(int64_t code);


    public:
        explicit ParserFile(std::string& path);

        std::queue<std::vector<std::string>> GetEventsQueue() const;
};
