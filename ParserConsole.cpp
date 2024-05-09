//
// Created by vitalii on 5/9/24.
//

#include "ParserConsole.h"
ParserConsole::ParserConsole(int argc, char *argv[]) {
    if (argc != 2) {
        throw ParserConsoleException(InvalidArgsNumExceptionMessage);
    }
    inputFilePath = argv[1];
    //TODO: кыш
//    std::cout<<inputFilePath<<"\n";
    std::filesystem::path path(inputFilePath);
//    std::cout<<path.extension()<<"\n";
    if (!(exists(path) && path.extension() == legalExtension)) {
        throw ParserConsoleException(InvalidFileMessage);
    }
}
std::string ParserConsole::GetInputFile() const {
    return inputFilePath;
}
