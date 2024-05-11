#include "BaseEvent.h"

//void BaseEvent::UploadExtra(std::unordered_map<std::string, std::string>&) {
//
//}
//void BaseEvent::UploadExtra(std::unordered_map<std::string, std::string>&)=0;
// TODO: Для каждого пусть будет свой особенный конструктор. extra будем передавать в фабрику
//BaseEvent::BaseEvent(std::tm& time, int64_t code, std::unordered_map<std::string, std::string>& extra): timeStamp(time), code(code) {
//    UploadExtra(extra);
//}

std::string BaseEvent::GetTwoDigitNumber(int64_t timeNumber) {
    std::string stringNum = std::to_string(timeNumber);
    if (stringNum.size() == 1) {
        stringNum.insert(0, "0");
    }
    return stringNum;
}

std::string BaseEvent::ConvertTimeStamp() const {
    std::string stringTimeStamp = GetTwoDigitNumber(timeStamp.tm_hour) + ":" + GetTwoDigitNumber(timeStamp.tm_min);
    return stringTimeStamp;
}

std::string BaseEvent::GetTimeTypePart() const {
    std::string timeType = ConvertTimeStamp() + " " + std::to_string(code);
    return timeType;
}

std::string BaseEvent::GetSpecialPart() const {
    return specialPart;
}

BaseEvent::BaseEvent(std::tm &timeStamp, int64_t code) : timeStamp(timeStamp), code(code) {}

std::string BaseEvent::GetPrintString() const {
    std::string printString = GetTimeTypePart() + GetSpecialPart();
    return printString;
}

std::ostream &operator<<(std::ostream &out, const BaseEvent *&event) {
    out << event->GetPrintString();
    return out;
}
