#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define Nbuff 150

#define DEF_CMD(name, num, cmd)\
    if(stricmp(temp_s, #name) == 0){\
        if(arr_p >= len){\
            len += 100;\
            arr = (double*) realloc(arr, len*sizeof(double));\
        }\
        arr[arr_p] = num;\
        arr_p++;\
        flag = 1;\
    }

int is_digit(char* str) {
    int i = 0, dots = 0;
    if(str == "" || str == " " || str[0] == '\n'){
        return 0;
    }
    if(str[0] == '-') {
        i++;
        if(strlen(str) == 1)
            return 0;
    }
    while(((str[i] >= '0' && str[i] <= '9') || (str[i] == '.')) && dots <= 1){
        if (str[i] == '.')
            dots++;
        i++;
    }
    if(str[strlen(str) - 1] == '\n')
        i++;
    return i == strlen(str) ? 1 : 0;
}

double get_digit(char* str) {
    double ans = 0;
    sscanf(str, "%lf", &ans);
    return ans;
}

double is_word(char* s) {
    int c = (int) s[0] - 'a';
    if(s[1] == 'x' && c <= 4 && c >= 0) {
        return (double) c;
    } else {
        return -1;
    }
}

int main(){
    FILE* cmd_in = fopen("cmds.asm.txt", "r");
    FILE* cmd_out = fopen("cmds.bin", "wb");
    FILE* temp_in = fopen("tempor.txt", "w+");
    assert(cmd_in);
    assert(cmd_out);
    assert(temp_in);

    int* arr_label = (int*) calloc(100, sizeof(int)); //ѕоиск меток
    int label_place = 0;
    char buff[Nbuff];//буферный массив
    while(fgets(buff, Nbuff, cmd_in) != NULL){
        printf("buff = '%s'", buff);
        if(buff[0] == '#'){
            int i = (int) (buff[1] - '0');
            printf("i = %d, label_place = %d\n", i, label_place);
            arr_label[i] = label_place;
        } else {
            char* s = (char*) calloc(Nbuff, sizeof(char));
            s = strcpy(s, buff);
            s = strtok(s, " ");
            while(s != NULL){
                s = strtok(NULL, " ");
                label_place++;
            }
           fprintf(temp_in, "%s", buff);
           free(s);
        }
    }
    rewind(temp_in);

    double* arr = (double*) calloc(100, sizeof(double));//выходной массив
    int flag = 0, arr_p = 0, len = 0;//flag of invalid command, arr_p - указатель на место в выходном массиве
    while(fgets(buff, Nbuff, temp_in) != NULL){
        char* temp_s = strtok(buff, " ");
            #include "Cmd_List.h"
            if(flag == 0){
                printf("Invalid command: %s", temp_s);
                continue;
            }
            temp_s = strtok(NULL, " ");
            double num;
            while(temp_s != NULL){
                if(temp_s[0] == '#'){
                    printf("temp#s = %s\n", temp_s);
                    int i = (int) (temp_s[1] - '0');
                    arr[arr_p] = arr_label[i];
                    arr_p++;
                }
                if(is_digit(temp_s)){
                    num = get_digit(temp_s);
                    if(arr_p >= len){
                        len += 100;
                        arr = (double*) realloc(arr, len*sizeof(double));
                    }
                    arr[arr_p] = num;
                    arr_p++;
                }
                num = is_word(temp_s);
                if(num >= 0){
                    if(arr_p >= len){
                        len += 100;
                        arr = (double*) realloc(arr, len*sizeof(double));
                    }
                    arr[arr_p] = num;
                    arr_p++;
                }
                temp_s = strtok(NULL, " ");
            }
            flag = 0;
    }
    arr[arr_p] = -1; //закрывающий элемент массива
    arr_p++;
    fwrite(arr, sizeof(double), arr_p, cmd_out);
    free(arr);
    free(arr_label);
    fclose(cmd_in);
    fclose(cmd_out);
    fclose(temp_in);
    return 1;
}
#undef DEF_CMD
