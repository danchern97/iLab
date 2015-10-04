#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int* a, int l, int f);
void swap(int* a, int i, int j);


int main(){
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
    QuickSort(a, 0, n-1);
    time_t t2 = time(NULL);
    for(j = 0; j < n; j++) {
        printf("a[%d] = %d\n", j, a[j]);
    }
    printf("Working time in seconds: %d", t2-t1);
    return 0;
}

void QuickSort(int* a, int left, int right){
    int l = left;
    int r = right;
    int m = a[(r+l)/2];
    while(l <= r){
        while((a[l] < m) && (l <= right)){
            l++;
        }
        while((a[r] > m) && (r >= left)){
            r--;
        }
        if(l <= r){
            swap(a, l, r);
            l++;
            r--;
        }
    }
    if(r > left){
        QuickSort(a, left, r);
    }
    if(l < right){
        QuickSort(a, l, right);
    }
}

void swap(int* a, int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
