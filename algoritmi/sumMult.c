#include <stdio.h>

int sumMult(int n){
    int sum = 0;
    int result = 1;

    for(int i = 1; i <= n; i++){
        sum += i;
        result *= sum;
    }

    return result;
}

int main(){
    printf("%d", sumMult(3));
    return 0;
}