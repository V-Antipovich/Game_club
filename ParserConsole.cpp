#include "ParserConsole.h"

ParserConsole::ParserConsole(int argc, char *argv[]) {
    if (argc != 2) {
        throw ParserConsoleException(InvalidArgsNumExceptionMessage);
    }
    inputFilePath = argv[1];
    std::filesystem::path path(inputFilePath);
    if (!(exists(path) && path.extension() == legalExtension)) {
        throw ParserConsoleException(InvalidFileMessage);
    }
}

std::string ParserConsole::GetInputFile() const {
    return inputFilePath;
}
