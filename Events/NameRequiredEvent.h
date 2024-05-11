#pragma once

#include "BaseEvent.h"

class NameRequiredEvent : public BaseEvent {
protected:
    std::string clientName;
public:
    NameRequiredEvent(std::tm &timeStamp, int64_t code, std::string &name);
};
