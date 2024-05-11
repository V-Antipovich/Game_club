#include "ClientGoneEvent.h"

ClientGoneEvent::ClientGoneEvent(std::tm &timeStamp, int64_t code, std::string &name) : NameRequiredEvent(timeStamp,
                                                                                                          code, name) {}

void ClientGoneEvent::Act() {
    // TODO: implement
}