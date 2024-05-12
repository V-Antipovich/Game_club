#pragma once

#include "NameRequiredEvent.h"
#include "../GamerClubEnv.h"
#include "ErrorEvent.h"
class ClientCameEvent : public NameRequiredEvent {
public:
    ClientCameEvent(TimeStamp &timeStamp, int64_t code, std::string &name);

    void Act(GamerClubEnv& env, std::queue<BaseEvent*>& outputQueue) override;
};
