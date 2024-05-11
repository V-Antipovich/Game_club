#pragma once

#include "NameRequiredEvent.h"

class NameTableRequiredEvent : public NameRequiredEvent {
protected:
    int64_t tableNum = 0;
public:
    NameTableRequiredEvent(TimeStamp &timeStamp, int64_t code, std::string &name, int64_t tableNum);
};
