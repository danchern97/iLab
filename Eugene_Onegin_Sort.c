#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 512

void s_bubble(char** ar, int len);

int main(){
    FILE* in_file = fopen("Eugene Onegin.txt", "r");
    FILE* out_file = fopen("Out.txt", "w");
    char buff[LEN];
    int len = 0, i = 0;
    if(in_file == NULL){
        fprintf(out_file, "Problems with in-file");
        return 0;
    }
    while(fgets(buff, LEN, in_file) != NULL){
        len++;
    }
    char** ar = (char**) malloc(sizeof(char*)*(len+1));
    if(ar == NULL){
        perror("No memory");
        return 0;
    }
    rewind(in_file);
    while(fgets(buff, LEN, in_file) != NULL){
        ar[i] = (char*) malloc((strlen(buff)+1)*sizeof(char));
        if(ar[i] == NULL){
            perror("No memory");
            return 0;
        }
        strcpy(ar[i], buff);
        i++;
    }
    i = 0;
    s_bubble(ar, len);
    while(i < len){
        if(i % 2 == 0){
            fprintf(out_file, "%s", ar[i]);
        }
        free(ar[i]);
        i++;
    }
    free(ar);
    fclose(in_file);
    fclose(out_file);
    return 0;
}

void s_bubble(char** ar, int len){
    int i, j;
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
            if(strcmp(ar[i], ar[j]) < 0){
                char* t = ar[i];
                ar[i] = ar[j];
                ar[j] = t;
            }
        }
    }
}
