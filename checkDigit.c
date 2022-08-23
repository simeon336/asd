#include <stdio.h>
#include <stdbool.h>

bool checkDigit(int n, int j){
    if(n == 0 && j == 0){
        return true;
    }
    for( ; n > 0; n/= 10){
        if(n % 10 == j){
            return true;
        }
    }

    return false;
}

int main(){
    if(checkDigit(376, 7)){
        printf("The number has the digit in it.");
    }
    else{
        printf("The number does not have the digit in it.");
    }
    return 0;
}