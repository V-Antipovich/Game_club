#pragma once

#include "NameRequiredEvent.h"

class ClientWaitingEvent : public NameRequiredEvent {
public:
    // TODO: Act override
    ClientWaitingEvent(std::tm &timeStamp, int64_t code, std::string &name);

    void Act() override;
};
