#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsDuplicate(int* nums, int numsSize){
    
    int count = 0;
    int check = 0;
    for(int i = 0; i < numsSize; i++){
        int temp = nums[i];
        for(int y = 0; y < numsSize; y++){
            if(temp == nums[y]){
                count++;
            }
        }
        if(count >= 2){
            check++;
        }
    }
    
    if(check >= 2){
        return true;
    } else{
        return false;
    }
}

int main(void){
    int size = 4;
    int *masiv = malloc(sizeof(int)*size);
    masiv[0] = 1;
    masiv[1] = 2;
    masiv[2] = 3;
    masiv[3] = 4;

    if(containsDuplicate(masiv, size)){
        printf("Da");
    } else{
        printf("ne");
    }

    return 0;
}