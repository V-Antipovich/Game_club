#include "ClientCameEvent.h"

ClientCameEvent::ClientCameEvent(TimeStamp &timeStamp, int64_t code, std::string &name) : NameRequiredEvent(timeStamp,
                                                                                                          code, name) {}

void ClientCameEvent::Act(GamerClubEnv& env, std::queue<BaseEvent*>& outputQueue) {
    int64_t clientID = env.AddIfNew(clientName);

    if (env.IsPresent(clientID)) {
        //TODO: мб константы строки потом тоже вынести куда-то
        std::unordered_map<std::string, std::string> extra =  {{"errorName", "YouShallNotPass"}};
        BaseEvent *err = CreateErrorEvent(timeStamp, errorCode, extra);
        outputQueue.push(err);
        return;
    }
    if (env.IsClosed(timeStamp)) {
        std::unordered_map<std::string, std::string> extra =  {{"errorName", "NotOpenYet"}};
        BaseEvent *err = CreateErrorEvent(timeStamp, errorCode, extra);
        outputQueue.push(err);
        return;
    }
    env.waitingGuests.push_back(clientID);
}