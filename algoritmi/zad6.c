#include <stdio.h>

void fibonachi(int n){
    int temp = 1;
    int prev = 0;
    int next;
    for(int i = 0; i <= n; i++){
        next = temp + prev;
        printf("%d: %d\n", i, next);
        prev = temp;
        temp = next;    
    }
}

int main(){
    fibonachi(10);

    return 0;
}