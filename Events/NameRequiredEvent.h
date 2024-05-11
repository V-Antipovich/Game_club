#pragma once

#include "BaseEvent.h"

class NameRequiredEvent : public BaseEvent {
protected:
    std::string clientName;
public:
    NameRequiredEvent(TimeStamp &timeStamp, int64_t code, std::string &name);
};
