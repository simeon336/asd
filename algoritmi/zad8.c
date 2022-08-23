#include <stdio.h>
#include <stdbool.h>


bool isPrime(int n){
    
    if(n == 0){
        return false;
    } else if(n == 1){
        return false;
    }
    else if(n % 2 == 0){
        if(n==2){
            return true;
        } else{
            return false;
        }
    } else if(n % 3 == 0){
        if(n == 3){
            return true;
        } else{
            return false;
        }
    } else if(n % 5 == 0){
        if(n == 5){
            return true;
        } else{
            return false;
        }
    } else if(n % 7 == 0){
        if(n == 7){
            return true;
        }
        else{
            return false;
        }
    } else{
        return true;
    }
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(isPrime(n)){
        printf("The numer is prime.");
    } else{
        printf("The number is not prime");
    }
    return 0;
}