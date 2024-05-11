#include "ClientWaitingEvent.h"

ClientWaitingEvent::ClientWaitingEvent(TimeStamp &timeStamp, int64_t code, std::string &name) : NameRequiredEvent(
        timeStamp, code, name) {}

void ClientWaitingEvent::Act() {
    // TODO: implement
    std::cout<<"ClientWaitingEvent playing\n";
}