#ifndef _COMPILECPP_H_
#define _COMPILECPP_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "variable.h"

// output file
char *cppfile = "main.cpp";

// generate function to convert strength enum to string
void generate_enum_switch(FILE** cpp) {
    fprintf(*cpp, "//to string for strength enum\nstring str(Strength s) {\nswitch(s) {\n");
    fprintf(*cpp, "    case regular: return \"regular\";\n    case strong: return \"strong\";\n    case iced: return \"iced\";\n    default: return \"regular\";\n   }\n}\n\n");
}

// generate lines: include libraries, variables, and functions
void addHeader(FILE** cpp) {
    fprintf(*cpp, "#include <iostream>\n#include <time.h>\n#include <chrono>\n#include <Windows.h>\nusing namespace std;\n\n");
    fprintf(*cpp, "//variables////////////////////////\n");
    for(int i = 0; i < var_count; i++) {
        if (strcmp(var_table[i]->type,"enum")==0){
            fprintf(*cpp, "%s %s {%s};\n", var_table[i]->type, var_table[i]->name, var_table[i]->val);

        } else {
            fprintf(*cpp, "%s %s = %s;\n", var_table[i]->type, var_table[i]->name, var_table[i]->val);

        }
    }
    fprintf(*cpp, "///////////////////////////////////\n");
    fprintf(*cpp, "\n");
    generate_enum_switch(cpp);
    fprintf(*cpp, "int main() {\n\n");
}

// generate output for brewing the coffee, check water_amount
void brew_gen(FILE** cpp) {
    fprintf(*cpp, "//brewing\n");
    fprintf(*cpp, "if (amount < water_amount) {\n");
    fprintf(*cpp, "    water_amount = water_amount - amount;\n    cout << \"Brewing...\\n\";\n    Sleep(1000);\n    cout << amount << \" ounce \" << str(strength) << \" coffee is ready!\\n\";\n");
    fprintf(*cpp, "} else { cout << no_water << amount << \" ounce coffee!\\n\";}\n\n");      
}

// generate code to output current time (HH:MM:SS)
void display_time(FILE** cpp) {
    fprintf(*cpp, "//display time\nt = time(0);\nlocal_time = localtime(&t);\ncout << \"Current Time: \" << local_time->tm_hour << \":\" << local_time->tm_min << \":\" << local_time->tm_sec << endl;\n\n");
}

// main program generation
void addProgram(FILE** cpp) {
    for (int i = 0; i < cmds; i++) {
        switch(cmd_list[i].code) {
            case PowerOn : fprintf(*cpp, "//turn power on\npower = true;\n\n"); break;
            case PowerOff: fprintf(*cpp, "//turn power off\npower = false;\n\n"); break;
            case Strength: fprintf(*cpp, "//set strength\nstrength = %s;\n\n", cmd_list[i].data); break;
            case Amount  : fprintf(*cpp, "//set amount\namount = %s;\n\n", cmd_list[i].data); break;
            case Brew    : brew_gen(cpp); break;
            case Time    : display_time(cpp); break;
        }
    }
}

// add closing bracket
void addFooter(FILE** cpp) {
    fprintf(*cpp, "}\n");
}

// open file, generate contents, close file
void compileCPP() {
    FILE* cpp = fopen(cppfile, "w");
    generate_var_table();
    addHeader(&cpp);
    addProgram(&cpp);
    addFooter(&cpp);
    fclose(cpp);
}

#endif