#include "ClientCameEvent.h"

ClientCameEvent::ClientCameEvent(TimeStamp &timeStamp, int64_t code, std::string &name) : NameRequiredEvent(timeStamp,
                                                                                                          code, name) {}

void ClientCameEvent::Act() {
    std::cout<<"ClientCameEvent playing\n";
}