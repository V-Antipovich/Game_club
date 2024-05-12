#include <iostream>
#include "ParserConsole.h"
#include "GamerClubEnv.h"
#include "ParserFile.h"
int main(int argc, char* argv[]) {
    try {
        // Парсим аргументы командной строки. Если формат неправильный или файла нет, мы выводим справку как надо вызывать
        ParserConsole parser_console = ParserConsole(argc, argv);
        auto path = parser_console.GetInputFile();
        std::cout<<path<<"\n";
        ParserFile parser_file = ParserFile(path);
        // TODO: вывод как просят в задаче
//        std::queue<Event*> inputQueue = parser_file.inputEventsQueue;
//        std::queue<Event*> outputQueue;
        GamerClubEnv env(parser_file.tablesNum, parser_file.costPerHour, parser_file.startWorkTime, parser_file.endWorkTime, parser_file.inputEventsQueue);
        env.HandleInputEvents();
        env.Print();
        //        while (!inputQueue.empty()) {
//            BaseEvent *event = inputQueue.front();
//            inputQueue.pop();
//            outputQueue.push(event);
//            event->Act(env, outputQueue);
//            delete event;
//        }
        // TODO: выгоняем всех кто не ушел, закидываем в массив и сортируем
//        std::cout<<env.GetStartWorkTime().PrintTime()<<"\n";
//        while (!outputQueue.empty()) {
//            BaseEvent *event = outputQueue.front();
//            outputQueue.pop();
//            std::cout<<event->GetPrintString()<<"\n";
////            delete event;
//        }
//        std::cout<<env.GetEndWorkTime().PrintTime()<<"\n";
        // TODO: принтуем выручку
        // Всех, кто не ушел - выгоняем, подсчитываем, записываем, вносим в очередь на Print

        // Разбираем очередь всех событий которые просто на Print
    } catch (const ParserConsoleException& pce) {
        std::cout<<"Чтобы программа корректно выполнилась, ей на вход необходимо предоставить один аргумент - путь до файла\n"
                   "Файл должен существовать и быть с расширением .txt";
    }

    return 0;
}
// TODO: 4) Собственно реализовывать задачу
// TODO: 5) Rule of three
// TODO: после всего) Тесты