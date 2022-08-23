#include <stdio.h>

void fibonachi(int n){
    int sum = 0;
    int temp = 1;
    int prev = 0;
    int next;
    for(int i = 0; i <= n; i++){
        next = temp + prev;
        sum += next;
        printf("%d: %d\n", i, next);
        prev = temp;
        temp = next;    
    }
    printf("The sum of the numbers is: %d", sum);
}
int main(){
    fibonachi(5);
    return 0;
}