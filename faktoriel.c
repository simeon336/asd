#include <stdio.h>

int faktoriel(int n){
    int sum = 1;
    for(int i = 1; i <= n; i++){
        sum *= i;
    }
    return sum;
}

int main(){
    printf("%d", faktoriel(18));
    return 0;
}