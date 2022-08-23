#include <stdio.h>

void swapVal(int a, int b){
    printf("A: %d, B: %d\n", a, b);
    int *x = &a;
    int *y = &b;
    int temp = *x;
    *x = *y;
    *y = temp;

    printf("A: %d, B: %d\n", a, b);
}

int main(void){


    swapVal(7, 9);


    return 0;
}