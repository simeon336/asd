#include <stdio.h>

void swap(int a, int b){
    printf("Before: a = %d, b = %d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("After: a = %d, b = %d", a, b);
}

int main(){
    swap(2, 36);
    return 0;
}