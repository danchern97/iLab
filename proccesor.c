#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Stack.c"

#define DEF_CMD(name, num, cmd)\
        case num:\
        cmd\
        break;

int len(FILE* cmd_in){
    int n = 0;
    while(fgetc(cmd_in) != EOF){
        n++;
    }
    n = n/8;
    printf("len = %d\n", n);
    rewind(cmd_in);
    return n;
}

int main(){
    FILE* cmd_in = fopen("cmds.bin", "rb");
    assert(cmd_in);
    int n = len(cmd_in), ip = 0, i = 0;
    double* cmd = (double*) calloc(n, sizeof(double));
    fread(cmd, sizeof(double), n, cmd_in);
    for(i = 0; i < n; i++){
        printf("cmd[%d] = %g\n", i, cmd[i]);
    }
    Stack* s = (Stack*) calloc(5, sizeof(Stack));
    for(i = 0; i < 5; i++){
        s[i] = create();
    }
    while(ip < n){
        switch((int) cmd[i]){
            #include "Cmd_List.h"
        }
        printf("\n\n\ncmd[%d]=%d\n", ip, (int)cmd[ip]);
        printf("before:\n");
        dump(&s[0]);
        getchar();
        if(cmd[ip] == -1){
            ip++;
            continue;
        }
        if(cmd[ip] == 1){
            int dest = (int) cmd[ip+1];
            push(&s[dest], cmd[ip+2]);
            ip += 3;
        } else
        if(cmd[ip] == 2){
            int dest = (int) cmd[ip+1];
            pop(&s[dest]);
            ip += 3;
        } else
        if(cmd[ip] == 3){
            int dest = (int) cmd[ip+1];
            int src = (int) cmd[ip+2];
            push(&s[dest], pop(&s[src]) + pop(&s[dest]));
            ip += 3;
        } else
        if(cmd[ip] == 4){
            int dest = (int) cmd[ip+1];
            int src = (int) cmd[ip+2];
            push(&s[dest], -pop(&s[src]) + pop(&s[dest]));
            ip += 3;
        } else
        if(cmd[ip] == 5){
            int dest = (int) cmd[ip+1];
            int src = (int) cmd[ip+2];
            push(&s[dest], pop(&s[src])*pop(&s[dest]));
            ip += 3;
        } else
        if(cmd[ip] == 6){
            int dest = (int) cmd[ip+1];
            int src = (int) cmd[ip+2];
            push(&s[dest], (1/pop(&s[src])*pop(&s[dest])));
            ip += 3;
        } else
        if(cmd[ip] == 7){
            int dest = (int) cmd[ip+1];
            int src = (int) cmd[ip+2];
            push(&s[dest], pop(&s[src]));
            ip += 3;
        } else
        if(cmd[ip] == 8){
            cmd[ip] = -1;
            int t = cmd[ip+1];
            cmd[ip+1] = -1;
            ip = t;
        } else
        if(cmd[ip] == 9){
            int dest = (int) cmd[ip+1];
            double t = pop(&s[dest]);
            if(t != 0){
                ip = cmd[ip+2];
            } else {
                ip += 3;
            }
            push(&s[dest], t);
        } else
        if(cmd[ip] == 10){
            int dest = (int) cmd[ip+1];
            double t = pop(&s[dest]);
            if(t == 0){
                ip = cmd[ip+2];
            } else {
                ip += 3;
            }
            push(&s[dest], t);
        }
        i++;
        printf("after:\n");
        dump(&s[0]);
    }

    dump(&s[0]);
    fclose(cmd_in);
    return 0;
}

#undef DEF_CMD
