#pragma once

#include <cstdint>
#include <string>
#include <stdexcept>
#include <regex>

// Поскольку от времени не требуется большого функционала, реализуем свой маленький класс
// Вместо использования ctime и пр.
class TimeStamp {
private:
    // Только для hour и minutes
    std::regex formatMatch = std::regex("[0-9]{2}:[0-9]{2}");
    static std::string TwoDigitNumber(int64_t n);
    void Validate(std::string& rawTimeStamp);
public:
    // 0 <= ... <= 23
    int64_t hours = 0;
    // 0 <= ... <= 59
    int64_t minutes = 0;

    static bool CorrectHours(int64_t h);

    static bool CorrectMinutes(int64_t m);

    [[nodiscard]] int64_t ConvertToMinutes() const;

    TimeStamp &operator=(const TimeStamp &other);

    TimeStamp() = default;

    TimeStamp(int64_t h, int64_t m);

    TimeStamp(TimeStamp &other);

    TimeStamp(TimeStamp&&)=default;

    ~TimeStamp()=default;

    explicit TimeStamp(std::string &rawTimeStamp);

    explicit TimeStamp(std::string &&rawTimeStamp);

    [[nodiscard]] std::string PrintTime() const;

    int64_t operator-(const TimeStamp& other) const;

    bool operator<(const TimeStamp& rhs) const;

    bool operator>(const TimeStamp& rhs) const;
};
