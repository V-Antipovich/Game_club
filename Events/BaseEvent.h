#pragma once
//#include <ctime>
#include <string>
#include <iostream>
#include <cstdint>
#include <unordered_map>
#include "../TimeStamp.h"
class BaseEvent {
    protected:
        std::string specialPart;
        int64_t code = 0;
        TimeStamp timeStamp;

        BaseEvent(TimeStamp &timeStamp, int64_t code);

    public:
        virtual void Act() = 0;

        virtual ~BaseEvent() = default;

        [[nodiscard]] std::string GetPrintString() const;
};
