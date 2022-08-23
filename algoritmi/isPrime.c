#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n){
    for(int i = 2; i < n/2; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    if(isPrime(73)){
        printf("It's a prime number");
    } else{
        printf("It's not a prime number");
    }
    return 0;
}