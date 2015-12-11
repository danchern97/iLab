#include <stdio.h>

int main(){
    FILE* in = fopen("cmds.bin", "rb");
    double* ar = (double*) calloc(100, sizeof(double));
    fread(ar, sizeof(double), 100, in);
    int i;
    for(i = 0; ar[i] != -1; i++){
        printf("%.3lg ", ar[i]);
    }
    fclose(in);
    free(ar);
    return 0;
}
