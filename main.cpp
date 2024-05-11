#include <iostream>
#include <fstream>
#include <queue>
#include "ParserConsole.h"
#include "ParserFile.h"

int main(int argc, char* argv[]) {
    try {
        // TODO: ?std::tm заменить на более легковсный класс - нам нужны только минуты и часы
        // Парсим аргументы командной строки. Если формат неправильный или файла нет, мы выводим справку как надо вызывать
        ParserConsole parser_console = ParserConsole(argc, argv);
        auto path = parser_console.GetInputFile();
        std::cout<<path<<"\n";
        ParserFile parser_file = ParserFile(path);
        // TODO: Создать окружение на основе объектов полученных от парсинга
        // TODO: вывод как просят в задаче

        while (!parser_file.inputEventsQueue.empty()) {
            auto ev = parser_file.inputEventsQueue.front();
            parser_file.inputEventsQueue.pop();
            ev->Act();
            std::cout << ev->GetPrintString() << "\n";
            delete ev;
        }
        // Всех, кто не ушел - выгоняем, подсчитываем, записываем, вносим в очередь на Print

        // Разбираем очередь всех событий которые просто на Print
    } catch (const ParserConsoleException& pce) {
        std::cout<<"Чтобы программа корректно выполнилась, ей на вход необходимо предоставить один аргумент - путь до файла\n"
                   "Файл должен существовать и быть с расширением .txt";
    }

    return 0;
}
// TODO: 3) Создать окружение событий: словари клиентов/столов/очередь
// TODO: 4) Собственно реализовывать задачу
// TODO: после всего) Тесты