#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next, *prev;
} node;

typedef struct list{
    struct node *head;
} list;

list *init(){
    list *List = malloc(sizeof(list));
    List->head = NULL;


    return List;
}

void add(list *List, int val){
    node *newNode = malloc(sizeof(node));
    newNode->val = val;

    if(List->head == NULL){
        List->head = newNode;
        newNode->next = NULL;
        newNode->prev = List->head;
        return;
    }

    node *temp = List->head;
    List->head = newNode;
    newNode->prev = List->head;
    newNode->next = temp;
    temp->prev = newNode;
}

void print(list *List){
    node* temp = List->head;
    while(temp != NULL){
        printf("<-%d->", temp->val);
        temp = temp->next;
    }
}

void reverse(list *List){
    node *temp = NULL;
    node *curr = List->head;

    while(curr != NULL){
        temp = curr->prev;
        temp->prev = curr;

    }
}

int main(){

    list *List = init();
    add(List, 4);
    add(List, 6);
    add(List, 1);
    add(List, 99);
    add(List, 1212);
    add(List, 878);
    print(List);

    return 0;
}