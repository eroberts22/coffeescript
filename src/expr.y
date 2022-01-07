%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src\variable.h"
#include "src\command.h"
#include "src\compilecpp.h"
#define YYDEBUG 1

int yylex (void);
int yyerror(char* s);

%}

%union semrec {
    char *val;
}
%start program
%token STRENGTH
%token AMOUNT
%token BREW
%token TIME
%token ON
%token OFF
%token LPAREN
%token RPAREN
%token <val> ID
%token <val> DIGIT

%%
program   : on stmt_list off;
stmt_list : stmt | stmt_list stmt;
stmt      : amount                       
          | strength    
          | BREW                        {gencode(Brew);}
          | TIME                        {gencode(Time);};
;
on        : ON                          {gencode(PowerOn);};
off       : OFF                         {gencode(PowerOff);};
amount    : AMOUNT LPAREN DIGIT RPAREN  {gencodeitem(Amount, $3);};
strength  : STRENGTH LPAREN ID RPAREN   {gencodeitem(Strength, $3);};                    

%%

int yyerror(char* s) {
    printf("error: %s\n", s);
}

int main(int argc, char**argv) {
    extern FILE* yyin;

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("%s doesn't exist\n", argv[1]);
            return -1;
        }
    }
    yyparse(); 
    compileCPP(); // compile cpp file from script
    cleanupVariables(); // cleanup allocated variables
}