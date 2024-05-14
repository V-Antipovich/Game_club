#pragma once

#include <cstdint>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "ParserConsoleException.h"

class ParserConsole {
private:
    std::string inputFilePath;
    const std::string legalExtension = ".txt";
    const std::string InvalidArgsNumExceptionMessage = "Некорректное количество аргументов";
    const std::string InvalidFileMessage = "Файла не существует или он расширения не .txt";
public:
    ParserConsole(int argc, char *argv[]);

    [[nodiscard]] std::string GetInputFile() const;
};