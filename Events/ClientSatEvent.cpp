#include "ClientSatEvent.h"

ClientSatEvent::ClientSatEvent(std::tm &timeStamp, int64_t code, std::string &name, int64_t tableNum)
        : NameTableRequiredEvent(timeStamp, code, name, tableNum) {}

void ClientSatEvent::Act() {
    // TODO: implement
}