#include <stdio.h>
#include <stdlib.h>

int *bubble(int *arr, size_t size){
    size_t len = size;
    for(int i = 0; i < size; i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    } 
    len--;
    if(len == 1){
        return arr;
    } else{
        bubble(arr, len);
    }
}

int main(){
    int arr[] = {8, 1, 5, 2, 9, 0, 23, 4, 6};
    size_t size = 9;
    bubble(arr, size);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}