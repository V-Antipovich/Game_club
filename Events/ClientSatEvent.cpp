#include "ClientSatEvent.h"

ClientSatEvent::ClientSatEvent(TimeStamp &timeStamp, int64_t code, std::string &name, int64_t tableNum)
        : NameTableRequiredEvent(timeStamp, code, name, tableNum) {}

void ClientSatEvent::Act() {
    // TODO: implement
    std::cout<<"ClientSatEvent playing\n";
}