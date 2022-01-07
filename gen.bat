win_flex src/expr.l 
win_bison -d  src/expr.y
gcc lex.yy.c expr.tab.c
.\a.exe src/test.expr
g++ main.cpp -o main.exe