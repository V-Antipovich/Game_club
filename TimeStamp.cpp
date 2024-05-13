#include "TimeStamp.h"

std::string TimeStamp::TwoDigitNumber(int64_t n) {
    std::string str_n = std::to_string(n);
    if (str_n.size() == 1) {
        str_n.insert(0, "0");
    }
    return str_n;
}

bool TimeStamp::CorrectHours(int64_t h) {
    return (0 <= h && h <= 23);
}

bool TimeStamp::CorrectMinutes(int64_t m) {
    return (0 <=m && m <= 59);
}

void TimeStamp::Validate(std::string& rawTimeStamp) {
    if (!(std::regex_match(rawTimeStamp.begin(), rawTimeStamp.end(), formatMatch) && CorrectHours(stoll(rawTimeStamp.substr(0, 2))) && CorrectMinutes(stoll(rawTimeStamp.substr(3, 2))))) {
        throw std::runtime_error("Incorrect format");
    }
}

int64_t TimeStamp::ConvertToMinutes() const {
    return hours*60 + minutes;
}

TimeStamp &TimeStamp::operator=(const TimeStamp &other) {
    if (this == &other) {
        return *this;
    }
    hours = other.hours;
    minutes = other.minutes;
    return *this;
}

TimeStamp::TimeStamp(int64_t h, int64_t m) : hours(h), minutes(m) {}

TimeStamp::TimeStamp(TimeStamp &other) {
    *this = other;
}

TimeStamp::TimeStamp(std::string &rawTimeStamp) {
    Validate(rawTimeStamp);
    // Используем только если уверены в правильности формата
    hours = stoll(rawTimeStamp.substr(0, 2));
    minutes = stoll(rawTimeStamp.substr(3, 2));

}

TimeStamp::TimeStamp(std::string &&rawTimeStamp) {
    hours = stoll(rawTimeStamp.substr(0, 2));
    minutes = stoll(rawTimeStamp.substr(3, 2));
}

std::string TimeStamp::PrintTime() const {
    std::string output = TwoDigitNumber(hours) + ":" + TwoDigitNumber(minutes);
    return output;
}

int64_t TimeStamp::operator-(const TimeStamp &other) const{
    return this->ConvertToMinutes() - other.ConvertToMinutes();
}

bool TimeStamp::operator<(const TimeStamp &rhs) const {
    return hours < rhs.hours || (hours == rhs.hours && minutes < rhs.minutes);
}

bool TimeStamp::operator>(const TimeStamp &rhs) const {
    return hours > rhs.hours || (hours == rhs.hours && minutes > rhs.minutes);
}
