#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include "Event.h"
#include "ParserFileError.h"

class ParserFile {
    private:
        const std::regex NumMatch = std::regex("[1-9][0-9]*");
        const std::regex startEndMatch = std::regex("[0-9]{2}:[0-9]{2} [0-9]{2}:[0-9]{2}");
        const std::regex eventMatch = std::regex(R"([0-9]{2}:[0-9]{2} [1-4] [a-z0-9\_\-]+[ [1-9]\d*]?)");
        const std::string nameKey = "name";
        const std::string tableNumKey = "tableNum";
        const std::unordered_set<int64_t> allowed_codes{1, 2, 3, 4};
        static bool IsTimeString(std::string& timeString);
    public:
        explicit ParserFile(std::string& path);
        std::queue<Event*> inputEventsQueue;
        int64_t tablesNum=0;
        int64_t costPerHour=0;
        TimeStamp startWorkTime;
        TimeStamp endWorkTime;
};
