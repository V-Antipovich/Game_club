#include <iostream>
#include "ParserConsole.h"
#include "GamerClubEnv.h"
#include "ParserFile.h"
int main(int argc, char* argv[]) {
    try {
        ParserConsole parser_console = ParserConsole(argc, argv);
        auto path = parser_console.GetInputFile();
        ParserFile parser_file = ParserFile(path);
        GamerClubEnv env(parser_file.tablesNum, parser_file.costPerHour, parser_file.startWorkTime, parser_file.endWorkTime, parser_file.inputEventsQueue);
        env.HandleInputEvents();
        env.Print();
    } catch (const ParserConsoleException& pce) {
        std::cout<<"Чтобы программа корректно выполнилась, ей на вход необходимо предоставить один аргумент - путь до файла\n"
                   "Файл должен существовать и быть с расширением .txt";
    }
    return 0;
}
