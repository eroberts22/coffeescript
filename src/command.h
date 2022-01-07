#ifndef COMMAND_H_
#define COMMAND_H_

// command codes
typedef enum {
    Brew, Strength, Amount, PowerOn, PowerOff, Time
} CODE;

typedef struct {
    CODE code;
    char* data;
} Cmd;

int cmds = 0;
Cmd cmd_list[50];

// add command to the command list
void addCommand(Cmd cmd) {
    if (cmds == 50) {
        printf("Overflow\n");
    } else {
        cmd_list[cmds++] = cmd;
    } 
}

// gencode for cmd with item
void gencodeitem(CODE code, char* item) {
    Cmd c;
    c.code = code;
    c.data = item;
    addCommand(c);
}

// gencode for cmd without item
void gencode(CODE code) {
    Cmd c;
    c.code = code;
    addCommand(c);
}

// helper function for print_commands
char* cmd_str(Cmd c) {
    switch (c.code) {
    case Brew: return "Brew";
    case Strength : return "Strength";
    case Amount : return "Amount";
    case PowerOn : return "PowerOn";
    case PowerOff : return "PowerOff";
    }
}

// function for testing, outputs command list 
void print_commands() {
    for(int i = 0; i < cmds; i++) {
        printf("%s\n", cmd_str(cmd_list[i]));
    }
}

#endif