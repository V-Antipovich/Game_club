//
// Created by vitalii on 5/9/24.
//

#include "ParserFile.h"
/*
 Данный код бросает ошибку, если значения количества столов и цены за час оказались неположительными.
 Предполагается логичным, что с точки зрения ведения бизнеса не предполагается обоснованным содержание
 компьютерного клуба без столов или с тарифом <= 0 р/час
 */
bool ParserFile::time_valid(std::string &timestamp) {
    return (timestamp.size() == 5 && timestamp[2] == ':' && isdigit(timestamp[0])
    && isdigit(timestamp[1]) && isdigit(timestamp[3]) &&isdigit(timestamp[4]));
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
        in>>tablesNum;
        in>>raw_start;
        in>>raw_end;
        in>>costPerHour;
        strptime(raw_start.c_str(), parseFormat, &startWorkTime);
        strptime(raw_end.c_str(), parseFormat, &endWorkTime);

        // Мы могли считать абсолютно некорректные данные времени.
        // Необходимо провалидировать их и кинуть при надобности ошибку
        if (!time_valid(raw_end) || !time_valid(raw_start)) {
            // TODO: многабукав в константы
            throw ParserFileError("Ошибка при вводе времени");
        }
        if (tablesNum <= 0 || costPerHour <= 0) {
            // TODO: многабукав в константы
            throw ParserFileError("Значения количества столов и тарифа должны быть целыми положительными");
        }
        // TODO: пока все в отвратном виде, надо запихать всё в Events
        // Надо понемногу воплощать функционал
        std::queue<std::vector<std::string>> q;
        while (in>>timeStamp>>eventType>>clientName) {
            std::vector<std::string> tmp;
            tmp.push_back(timeStamp);
            tmp.push_back(std::to_string(eventType));
            tmp.push_back(clientName);
            if (eventType==2) {
                in>>tableNum;
                tmp.push_back(std::to_string(tableNum));
            }
            q.push(tmp);
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