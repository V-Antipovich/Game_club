#include "ParserFile.h"
/*
 Данный код бросает ошибку, если значения количества столов и цены за час оказались неположительными.
 Предполагается логичным, что с точки зрения ведения бизнеса не предполагается обоснованным содержание
 компьютерного клуба без столов или с тарифом <= 0 р/час
 */
bool ParserFile::is_time_valid(std::string &timestamp) {
    return (timestamp.size() == 5 && timestamp[2] == ':' && isdigit(timestamp[0])
    && isdigit(timestamp[1]) && isdigit(timestamp[3]) &&isdigit(timestamp[4]));
}

bool ParserFile::is_code_valid(int64_t code) {
    auto it = allowed_codes.find(code);
    return it != allowed_codes.end();
}

ParserFile::ParserFile(std::string& path) {
    std::ifstream in;
    in.open(path);
    try {
        int64_t eventType=0;
        int64_t tableNum=0;
        std::string raw_start;
        std::string raw_end;
        std::string clientName;
        std::string stringTimeStamp;
        in >> tablesNum; // TODO: ее сначала надо в виде строки
        if (tablesNum <= 0) {
            // TODO: многабукав в константы + тут надо выплевывать ошибку с завершением программы
            throw ParserFileError("Значения количества столов и тарифа должны быть целыми положительными");
        }

        in>>raw_start;
        if (false) { // TODO: валидация и выплевываем если что
            throw ParserFileError();
        }
        startWorkTime = TimeStamp(raw_start);

        in>>raw_end;
        if (false) { // TODO: валидация и выплевываем если что
            throw ParserFileError();
        }
        endWorkTime = TimeStamp(raw_end);

        in>>costPerHour;
        if (false) { // TODO: валидация и выплевываем если что
            throw ParserFileError();
        }

        std::queue<std::vector<std::string>> q;
        std::unordered_map<std::string, std::string> extra;
        TimeStamp eventTime;
        auto eventsMap = CreateEventsMap();
        while (in>>stringTimeStamp>>eventType>>clientName) {
            extra.clear();
            // TODO: validate
            eventTime = TimeStamp(stringTimeStamp);
            extra[nameKey] = clientName;
            // TODO: валидируем: надо cin.getline вообще
            // TODO: Стол номера не больше чем надо
            // TODO: Последовательные события проверка
            if (eventType==2) {
                in >> tableNum;
                extra[tableNumKey] = std::to_string(tableNum);
            }

            inputEventsQueue.push(eventsMap[eventType](eventTime, eventType, extra));

        }
        in.close();
    } catch (std::exception &ex) {
        in.close();
        throw ParserFileError(ex.what());
    }
}
