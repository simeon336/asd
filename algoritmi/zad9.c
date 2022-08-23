#include <stdio.h>
#include <math.h>

int numOfDigits(int n){
    int count = 1;
    while(n / 10 >= 1){
        count++;
        n /= 10;
    }
    return count;
}

int main(){
    int n;
    printf("Enter number: ");
    
    printf("Number of digits in the number are: %d", numOfDigits(33776));
    return 0;
}