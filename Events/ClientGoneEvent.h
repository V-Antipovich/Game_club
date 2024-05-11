#pragma once

#include "NameRequiredEvent.h"

class ClientGoneEvent : public NameRequiredEvent {
    // TODO: ACT override
    public:
        ClientGoneEvent(std::tm &timeStamp, int64_t code, std::string &name);

        void Act() override;
};
