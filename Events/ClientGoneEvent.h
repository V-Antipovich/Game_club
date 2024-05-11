#pragma once

#include "NameRequiredEvent.h"

class ClientGoneEvent : public NameRequiredEvent {
    // TODO: ACT override
    public:
        ClientGoneEvent(TimeStamp &timeStamp, int64_t code, std::string &name);

        void Act() override;
};
