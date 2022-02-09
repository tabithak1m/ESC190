#include <stdio.h>
#include <stdlib.h>

void f(int* a){
    *a = 10;
}

void printArr(int a[]){
    int i = 0;
    for(i = 0; i < 5; i++){
        printf("%d, ", a[i]);
    }
}

void insertionSort(int arr[], int length){
    int i;
    for(i = 1; i < length; i++){
        int j;
        for(j = 0; j < i; j++){
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main(void) {
    int a = 5;
    printf("Before: %d\n", a);
    f(&a);
    printf("After: %d\n", a);
    int arr[5] = {5,2,3,4,1};
    printArr(arr);
    printf("\n////////////////////////\n");
    insertionSort(arr, sizeof(arr)/sizeof(int));
    printArr(arr);

    return 0;
}