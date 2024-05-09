//
// Created by vitalii on 5/9/24.
//

#pragma once
#include <string>
#include <cstdint>
#include <ctime>
#include <fstream>
#include "ParserFileError.h"
#include <sstream>
#include <iomanip>
#include <queue>

class ParserFile {
    private:
        const char *parseFormat = "%H:%M";
        int64_t tablesNum=0;
        int64_t costPerHour=0;
        std::tm startWorkTime;
        std::tm endWorkTime;
//        std::queue<BaseEvent*>
        std::queue<std::vector<std::string>> args;
        static bool time_valid(std::string& timestamp);

    public:
        explicit ParserFile(std::string& path);

        std::queue<std::vector<std::string>> GetEventsQueue() const;
};
