#include <stdio.h>

int sumN(int n){
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += i;
    }
    return sum;
}

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("%d", sumN(n));
    return 0;
}