#include <stdio.h>

void ednoDoN(int n){
    for(int i = 1; i <= n; i++){
        printf("%d\n", i);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    ednoDoN(n);
    return 0;
}