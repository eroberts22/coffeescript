%{
    #include "expr.tab.h"
    #define YY_SKIP_YYWRAP 
    int yywrap() {return 1;}
%}

DIGIT [0-9]
ID [a-z][a-z0-9]*
LPAREN [(]
RPAREN [)]

%%

"strength" {
    return (STRENGTH);
}

"amount" {
    return (AMOUNT);
}

"powerOn" {
    return (ON);
}

"powerOff" {
    return (OFF);
}

"brew" {
    return (BREW);
}

"displayTime" {
    return (TIME);
}

{DIGIT}+ {
    yylval.val = (char*) strdup(yytext);
    return (DIGIT);
}

{ID} {
    yylval.val = (char*) strdup(yytext);
    return (ID);
}

{LPAREN} {
    yylval.val = (char*) strdup(yytext);
    return (LPAREN);
}

{RPAREN} {
    yylval.val = (char*) strdup(yytext);
    return (RPAREN);
}

[ \t\n\r]+ /* eat up whitespace */
. { printf( "Unknown: '%s'\n", yytext ); }

%%


