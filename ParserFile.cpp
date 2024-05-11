//
// Created by vitalii on 5/9/24.
//

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
        std::string timeStamp;
        in >> tablesNum; // TODO: ее сначала надо в виде строки
        if (tablesNum <= 0) {
            // TODO: многабукав в константы + тут надо выплевывать ошибку с завершением программы
            throw ParserFileError("Значения количества столов и тарифа должны быть целыми положительными");
        }

        in>>raw_start;
        if (false) { // TODO: валидация и выплевываем если что
            throw ParserFileError();
        }
        in>>raw_end;
        if (false) { // TODO: валидация и выплевываем если что
            throw ParserFileError();
        }
        in>>costPerHour;
        if (false) { // TODO: валидация и выплевываем если что
            throw ParserFileError();
        }
        strptime(raw_start.c_str(), parseFormat, &startWorkTime);
        strptime(raw_end.c_str(), parseFormat, &endWorkTime);

        std::queue<std::vector<std::string>> q;
        std::unordered_map<std::string, std::string> extra;
        // TODO: внедрить фабрику
//        auto eventsMap =
        while (in>>timeStamp>>eventType>>clientName) {
            extra.clear();
            // TODO: валидируем: надо cin.getline вообще
            // TODO: Стол номера не больше чем надо
            // TODO: Последовательные события проверка
            if (eventType==2) {
                in >> tableNum;
            }

//            std::vector<std::string> tmp;
//            tmp.push_back(timeStamp);
//            tmp.push_back(std::to_string(eventType));
//            tmp.push_back(clientName);

//                tmp.push_back(std::to_string(tableNum));
//            }
//            q.push(tmp);
        }
        in.close();
        args = q;
    } catch (std::exception &ex) {
        in.close();
        throw ParserFileError(ex.what());
    }
}

std::queue<std::vector<std::string>> ParserFile::GetEventsQueue() const {
    return args;
}