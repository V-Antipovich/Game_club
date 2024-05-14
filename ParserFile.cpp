#include "ParserFile.h"

bool ParserFile::IsTimeString(std::string &timeString) {
    return TimeStamp::CorrectHours(stoll(timeString.substr(0, 2))) &&
           TimeStamp::CorrectMinutes(stoll(timeString.substr(3, 2)));
}

ParserFile::ParserFile(std::string &path) {
    std::ifstream in;
    in.open(path);
    int64_t eventType = 0;
    int64_t tableNum = 0;
    std::string rawTableNum;
    std::string rawStartEnd;
    std::string rawTimeStamp;
    std::string rawCostPerHour;
    std::string clientName;
    std::string stringTimeStamp;
    std::string rawEvent;
    TimeStamp eventTime;
    TimeStamp prevTime;

    std::getline(in, rawTableNum);
    if (!(in.good() && std::regex_match(rawTableNum.begin(), rawTableNum.end(), NumMatch))) {
        throw ParserFileError(rawTableNum);
    }
    std::stringstream sst(rawTableNum);
    sst >> tablesNum;

    std::getline(in, rawStartEnd);
    if (in.good() && std::regex_match(rawStartEnd.begin(), rawStartEnd.end(), startEndMatch)) {
        auto s1 = rawStartEnd.substr(0, 5);
        auto s2 = rawStartEnd.substr(6, 5);
        if (!IsTimeString(s1) || !IsTimeString(s2)) {
            throw ParserFileError(rawStartEnd);
        }
    } else {
        throw ParserFileError(rawStartEnd);
    }
    startWorkTime = TimeStamp(rawStartEnd.substr(0, 5));
    endWorkTime = TimeStamp(rawStartEnd.substr(6, 5));
    if (startWorkTime > endWorkTime) {
        throw ParserFileError(rawStartEnd);
    }
    std::getline(in, rawCostPerHour);
    if (!((in.good() || in.eof()) && std::regex_match(rawCostPerHour.begin(), rawCostPerHour.end(), NumMatch))) {
        throw ParserFileError(rawCostPerHour);
    }
    costPerHour = stoll(rawCostPerHour);

    Event *event = nullptr;
    bool first = true;
    while (std::getline(in, rawEvent)) {
        if (!((in.good() || in.eof()) && (std::regex_match(rawEvent.begin(), rawEvent.end(), eventMatch1) ||
                                          std::regex_match(rawEvent.begin(), rawEvent.end(), eventMatch2)))) {
            throw ParserFileError(rawEvent);
        }
        std::stringstream ss(rawEvent);
        ss >> rawTimeStamp >> eventType >> clientName;
        eventTime = TimeStamp(rawTimeStamp);
        if (!(first || !(eventTime < prevTime))) {
            throw ParserFileError(rawEvent);
        }
        first = false;
        prevTime = eventTime;
        if (eventType == 2) {
            ss >> tableNum;
            if (tableNum > tablesNum) {
                throw ParserFileError(rawEvent);
            }
            event = new Event(eventTime, eventType, clientName, tableNum);
        } else {
            event = new Event(eventTime, eventType, clientName);
        }
        inputEventsQueue.push(event);
    }
}
