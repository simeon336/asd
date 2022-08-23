#include <stdio.h>
#include <stdlib.h>

int *insertion(int *arr, size_t size){
    for(int i = 0; i < size; i++){
        int temp = arr[i];
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j]){
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main(){
   int arr[] = {8, 1, 5, 2, 9, 0, 23, 4, 6};
    size_t size = 9;
    insertion(arr, size);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}