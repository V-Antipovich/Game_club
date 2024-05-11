#pragma once

#include <unordered_map>
#include <cstdint>
#include <functional>
#include "BaseEvent.h"
#include "ClientCameEvent.h"
#include "ClientSatEvent.h"
#include "ClientWaitingEvent.h"
#include "ClientGoneEvent.h"
#include "ErrorEvent.h"
// Не класс, а набор функций для создания мапы-фабрики событий

BaseEvent *
CreateClientCameEvent(TimeStamp &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra);

BaseEvent *
CreateClientSatEvent(TimeStamp &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra);

BaseEvent *
CreateClientWaitingEvent(TimeStamp &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra);

BaseEvent *
CreateClientGoneEvent(TimeStamp &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra);

BaseEvent *CreateErrorEvent(TimeStamp &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra);

std::unordered_map<int64_t, std::function<BaseEvent *(TimeStamp &, int64_t,
                                                      std::unordered_map<std::string, std::string> &)>>
CreateEventsMap();

