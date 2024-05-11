#pragma once
//#include <ctime>
#include <string>
#include <queue>
#include <iostream>
#include <cstdint>
#include <unordered_map>
#include "../TimeStamp.h"
//#include "../ClientsBase.h"
#include "../GamerClubEnv.h"

class BaseEvent {
    protected:
        std::string specialPart;
        int64_t code = 0;
        TimeStamp timeStamp;

        BaseEvent(TimeStamp &timeStamp, int64_t code);

    public:
        // TODO: аргумент - окружение
        virtual void Act(GamerClubEnv&, std::queue<BaseEvent*>&) = 0;

        virtual ~BaseEvent() = default;

        [[nodiscard]] std::string GetPrintString() const;
};
