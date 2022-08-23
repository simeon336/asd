#include <stdio.h>
#include <stdbool.h>



bool isPowerOfTwo(int n){
    int i = 1;
    while(i <= n){
        if(n==i){
            return true;
        }
        i *= 2;
    }
    return false;
}

int main(void){
    if(isPowerOfTwo(8)){
        printf("True");
    } else{
        printf("false");
    }
    return 0;
}