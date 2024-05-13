# Тестовое задание на стажировку YADRO
## Позиция "Инженер по разработке ПО для базовых станций (С++)"

В реализации основного функционала была использована только стандартная библиотека C++ 20

Сборка осуществлялась посредством cmake 3.27

Для тестирования применена Google Tests (в файле тз было разрешено; предполагается, что эта библиотека установлена на машине и может быть вызвана посредством ```#include <...>```)

Компилятор: clang 17.0.6

ОС: Fedora 39
### Инструкция по сборке
1) Клонировать себе репозиторий
```
git clone https://github.com/V-Antipovich/Game_club.git YOURFOLDER
```
2) Перейти в папку проекта, внутри нее - в ```cmake-build-debug```
```
cd YOURGOLDER/cmake-build-debug
```
3) Собрать посредством cmake
```
cmake --build .
```
4) Чтобы запустить, в той же папке вводим имя программы ```gamer_club``` с аргументом - путь к файлу ```.txt```
```
./gamer_club PATHTOFILE.txt
```
