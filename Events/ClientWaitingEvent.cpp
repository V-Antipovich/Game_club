#include "ClientWaitingEvent.h"

ClientWaitingEvent::ClientWaitingEvent(std::tm &timeStamp, int64_t code, std::string &name) : NameRequiredEvent(
        timeStamp, code, name) {}

void ClientWaitingEvent::Act() {
    // TODO: implement
    std::cout<<"ClientWaitingEvent playing\n";
}