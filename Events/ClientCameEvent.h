#pragma once

#include "NameRequiredEvent.h"

class ClientCameEvent : public NameRequiredEvent {
public:
    ClientCameEvent(std::tm &timeStamp, int64_t code, std::string &name);

    void Act() override; // TODO: ACT implement
};
