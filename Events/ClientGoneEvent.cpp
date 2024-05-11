#include "ClientGoneEvent.h"

ClientGoneEvent::ClientGoneEvent(TimeStamp &timeStamp, int64_t code, std::string &name) : NameRequiredEvent(timeStamp,
                                                                                                          code, name) {}

void ClientGoneEvent::Act(GamerClubEnv& env, std::queue<BaseEvent*>& outputQueue) {
    // TODO: implement
    std::cout<<"ClientGoneEvent playing\n";
}