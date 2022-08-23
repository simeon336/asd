#include <stdio.h>

void chislaNaTri(int n){
    int sum = 0;
    for(int i = 0; i <= n; i++){
        if(i % 3 == 0){
            sum += i;
        }
    }
    if(sum == 0){
        printf("Nqma chisla, koito se delqt na 3");
    }
    else{
        printf("%d", sum);
    }
}

int main(){
    chislaNaTri(6);
    return 0;
}