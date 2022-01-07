# Documentation

## File Descriptions

| File         | Description                                     |
|--------------|-------------------------------------------------|
| expr.l       | scanner                                         |
| expr.y       | parser                                          |
| test.expr    | keurig test script                              |
| variable.h   | generate and store script variables             |
| command.h    | generate and store script commands              |
| compilecpp.h | compile script variables/commands into cpp file |

## Language Design

| Command         | Description                                  |
|-----------------|----------------------------------------------|
| powerOn         | turn the coffee machine on                   |
| powerOff        | turn the coffee machine off                  |
| displayTime     | output the current time (HH:MM:SS)           |
| amount(`int`)   | set amount of coffee in ounces               |
| strength(`var`) | set strength of coffee (regular,strong,iced) |
| brew            | brew the coffee at specified strength/amount |

## Build Instructions
In command line in top directory
1. Run `.\gen.bat`
2. Run `.\main`

### .\gen.bat File

Contains commands to convert the script to C++

    win_flex src/expr.l 
    win_bison -d src/expr.y 
    gcc lex.yy.c expr.tab.c
    .\a.exe src/test.expr
    g++ main.cpp -o main.exe

## Sources

- EX03/EX04
- in class lectures
- https://www.softwaretestinghelp.com/date-and-time-in-cpp/
- https://stackoverflow.com/questions/4184468/sleep-for-milliseconds