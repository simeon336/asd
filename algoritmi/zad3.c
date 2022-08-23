#include <stdio.h>
#include <stdbool.h>

bool deliNaTri(int n){
    if(n % 3 == 0){
        return true;
    } else {
        return false;
    }
}

int main(){

    if(deliNaTri(4)){
        printf("Deli se");
    } else {
        printf("Ne se deli");
    }

    return 0;
}