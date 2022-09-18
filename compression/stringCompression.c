#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int count;
    char *str;
    struct node *next;
} node;

typedef struct list{
    struct node* head;
} list;

list *init(){
    list *List = (list*)malloc(sizeof(list));
    List->head = NULL;

    return List;
}

void add(list *List, char* str){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->str = (char*)malloc(sizeof(char)*4);
    
    if(List->head == NULL){
        List->head = newNode;
        newNode->next = NULL;
        newNode->count = 1;
        return;
    }

    node *temp = List->head;
    while(temp != NULL){
        if(strcmp(temp->str, str) == 0){
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    temp = List->head;
    List->head = newNode;
    newNode->next = temp;
}

void listPrint(list *List){
    node *temp = List->head;
    while(temp != NULL){
        printf("%s->", temp->str);
        temp = temp->next;
    }
}

// typedef struct table{
//     int x;
//     struct node**

// }

char *compress(char *str, int x){ // x e kolko bukvena posledovatelnost

}

int main(){
    list *List = init();
    add(List, "klk");
    add(List, "kls");
    listPrint(List);
    return 0;
}