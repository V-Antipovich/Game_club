#pragma once

#include "BaseEvent.h"

class ErrorEvent : public BaseEvent {
protected:
    std::string errorName;
public:
    ErrorEvent(std::tm &timeStamp, int64_t code, std::string &error);

    void Act() override;
};
