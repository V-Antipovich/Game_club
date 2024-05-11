#pragma once
#include <ctime>
#include <string>
#include <iostream>
#include <cstdint>
#include <unordered_map>

class BaseEvent {
    private:
        [[nodiscard]] static std::string GetTwoDigitNumber(int64_t timeNumber);

        [[nodiscard]] std::string ConvertTimeStamp() const;

        // Для вывода: общая часть у всех типов событий одинаковая: время и тип
        [[nodiscard]] std::string GetTimeTypePart() const;

    protected:
        std::string specialPart;
        int64_t code = 0;
        std::tm timeStamp = {};

        [[nodiscard]] std::string GetSpecialPart() const;

        BaseEvent(std::tm &timeStamp, int64_t code);
        //        virtual void UploadExtra(std::unordered_map<std::string, std::string>&)=0;

    public:
    //        BaseEvent(std::tm& time, int64_t code, std::unordered_map<std::string, std::string>& extra);
        BaseEvent() = default;

        virtual void Act() = 0;

        virtual ~BaseEvent() = default;

        [[nodiscard]] std::string GetPrintString() const;
};

std::ostream &operator<<(std::ostream &out, const BaseEvent *&event);
