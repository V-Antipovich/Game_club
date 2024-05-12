#pragma once

#include "NameTableRequiredEvent.h"

class ClientSatEvent : public NameTableRequiredEvent {
    public:
        ClientSatEvent(TimeStamp &timeStamp, int64_t code, std::string &name, int64_t tableNum);

        void Act(GamerClubEnv& env, std::queue<BaseEvent*>& outputQueue) override;
};
