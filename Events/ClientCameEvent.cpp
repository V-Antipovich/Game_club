#include "ClientCameEvent.h"

ClientCameEvent::ClientCameEvent(std::tm &timeStamp, int64_t code, std::string &name) : NameRequiredEvent(timeStamp,
                                                                                                          code, name) {}

void ClientCameEvent::Act() {

}