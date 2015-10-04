#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* BubbleSort(int* a, int n);
time_t time(time_t *tp);

int main() {
    int i, j, n;
    printf("Enter the length of the array and the array itself:\n");
    if(scanf("%d", &n) != 1) {
        printf("Wrong input");
        return 0;
    }
    int a[n];
    for(i = 0; i < n; i++) {
        if(scanf("%d", &a[i]) != 1){
            printf("Wrong input");
            return 0;
        }
    }
    time_t t1 = time(NULL);
    int* res = BubbleSort(a, n);
    time_t t2 = time(NULL);
    for(j = 0; j < n; j++) {
        printf("a[%d] = %d\n", j, res[j]);
    }
    printf("Working time in seconds: %d", t2-t1);
    return 0;
}

int* BubbleSort(int* a, int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    return a;
}
