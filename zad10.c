#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char *my_itoa(int num, char *str)
{
        if(str == NULL)
        {
                return NULL;
        }
        sprintf(str, "%d", num);
        return str;
}

bool checkNum(int n, int cifra){
    char *bigN = malloc(sizeof(int)*256);
    char nn = cifra + '0';
    int len = 4;
    my_itoa(n, bigN);
    
    for(int i = 0; i < len; i++){
        if(bigN[i] == nn){
            return true;
        }
    }
    return false;
}

int main(){
    if(checkNum(4216, 6)){
        printf("Yes.");
    } else{
        printf("No");
    }
    return 0;
}