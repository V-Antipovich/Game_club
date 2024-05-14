#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Event.h"
#include "ParserFileError.h"

class ParserFile {
    private:
        const std::regex NumMatch = std::regex("[1-9][0-9]*");
        const std::regex startEndMatch = std::regex("[0-9]{2}:[0-9]{2} [0-9]{2}:[0-9]{2}");
        const std::regex eventMatch1 = std::regex("[0-9]{2}:[0-9]{2} [134] [a-z0-9_-]+");
        const std::regex eventMatch2 = std::regex("[0-9]{2}:[0-9]{2} 2 [a-z0-9_-]+ [1-9][0-9]*");
        static bool IsTimeString(std::string& timeString);
    public:
        explicit ParserFile(std::string& path);
        std::queue<Event*> inputEventsQueue;
        int64_t tablesNum=0;
        int64_t costPerHour=0;
        TimeStamp startWorkTime;
        TimeStamp endWorkTime;
};
