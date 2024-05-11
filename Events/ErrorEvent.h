#pragma once

#include "BaseEvent.h"

class ErrorEvent : public BaseEvent {
protected:
    std::string errorName;
public:
    ErrorEvent(TimeStamp &timeStamp, int64_t code, std::string &error);

    void Act(GamerClubEnv& env, std::queue<BaseEvent*>& outputQueue) override;
};
