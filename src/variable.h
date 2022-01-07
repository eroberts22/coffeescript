#ifndef _VARIABLE_H_
#define _VARIABLE_H_
#include <string.h>
#include "command.h"

// variable struct
typedef struct {
    char* type;
    char* name;
    char* val;
} Variable;

int var_count = 0;
Variable* var_table[100];

// create new variable and add to table
void add_var(char* t, char* n, char* v) {
    Variable *var = malloc(sizeof(Variable));
    var->type = t;
    var->name = n;
    var->val = v;
    var_table[var_count++] = var;
}

// generate the table with initial variables
// these variables are necessary in cpp program
void generate_var_table() {
    add_var("int","water_amount","30");
    add_var("bool","power","false");
    add_var("int","amount","4");
    add_var("enum","Strength","regular,strong,iced");
    add_var("Strength","strength","regular");
    add_var("string","no_water","\"Not enough water to brew \"");
    add_var("time_t","t","time(0)");
    add_var("tm","*local_time","localtime(&t)");
}

// free the symbols in the symbol table
void cleanupVariables() {
    for (int i = 0; i < var_count; i++) {
        free(var_table[i]);
    }
}

#endif