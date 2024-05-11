#include <iostream>
#include <fstream>
#include <queue>
#include "ParserConsole.h"
#include "ParserFile.h"

int main(int argc, char* argv[]) {
    try {
        // Парсим аргументы командной строки. Если формат неправильный или файла нет, мы выводим справку как надо вызывать
        ParserConsole parser_console = ParserConsole(argc, argv);
        auto path = parser_console.GetInputFile();
        std::cout<<path<<"\n";
        ParserFile parser_file = ParserFile(path);
//        auto q = parser_file.GetEventsQueue();
//        while (!q.empty()) {
//            for (auto s: q.front()) {
//                std::cout<<s<<" ";
//            }
//            q.pop();
//            std::cout<<"\n";
//        }
    } catch (const ParserConsoleException& pce) {
        std::cout<<"Чтобы программа корректно выполнилась, ей на вход необходимо предоставить один аргумент - путь до файла\n"
                   "Файл должен существовать и быть с расширением .txt";
    }

    return 0;
}
// TODO: 1) Форматирование даты std::tm
// TODO: 2) Все разные классы Событий
// TODO: 3) Создать окружение событий: словари клиентов/столов/очередь
// TODO: 4) Собственно реализовывать задачу
// TODO: ) Тесты