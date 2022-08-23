#include <stdio.h>

void decToBin(int n){
    int arr[10];
    int count = 0;

    while(n > 1){
        arr[count] = n % 2;
        n = n / 2;
    
        count++;
        
    }
    arr[count+1]=1;

    int reverse[10];
    int cnt=0;
    for(int i=10; i>=0; i--){
        reverse[cnt]=arr[i];
        cnt++;
    }

    for(int i=0; i<10; i++){
        printf("%d\n", reverse[i]);
    }
    // int newArr[9];
    // int newCnt = 0;
    // newArr[0] = 1;
    // for(int i = 9; i > 0; i--){
    //     newArr[newCnt] = arr[i];
    //     printf("%d", newArr[newCnt]);
    //     newCnt++;
       
    // }
}

int main(){
    decToBin(432);
    return 0;
}