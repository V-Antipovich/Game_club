#pragma once
#include "TimeStamp.h"
class Event {
    public:
        TimeStamp timeStamp;
        int64_t ID=0;
        std::string clientName;
        int64_t tableNum=0;
        std::string error;
        std::string specialPart;
        Event(TimeStamp& timeStamp, int64_t ID, std::string& name, int64_t tableNum);
        Event(TimeStamp& timeStamp, int64_t ID, std::string& str, bool isError= false);
        [[nodiscard]] std::string to_str() const;
};
