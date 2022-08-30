#include <stdio.h>

void oneToN(int n){
    if(n > 1){
        oneToN(n-1);
    }
    printf("%d", n);

}

int main(){
    oneToN(5);

    return 0;
}