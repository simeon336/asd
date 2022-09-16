#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compresion(char *str){
    size_t len = strlen(str);
    int repeat[len];
    for(int i = 0; i < len; i++){
        repeat[i] = 0;
    }
    char temp;
    for(int i = 0; i < len; i++){
        temp = str[i];
        for(int j = 0; j < i; j++){
            if(temp = str[j]){
                repeat[i]++;
            }
        }
    }
}

int main(){
    compresion("ghjkljhgtyjmjhytfvhuytgf");

    return 0;
}