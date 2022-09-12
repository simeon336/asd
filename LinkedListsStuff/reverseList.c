#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} node;

typedef struct list{
    struct node *head;
} list;

list *init(){
    list *newList = malloc(sizeof(list));
    newList->head = malloc(sizeof(node));
    newList->head = NULL;
    return newList;
}

void add(list *List, int val){
    node *newNode = malloc(sizeof(node));
    newNode->val = val;

    if(List->head == NULL){
        List->head = newNode;
        newNode->next = NULL;
        return;
    }

    node *temp = List->head;
    List->head = newNode;
    newNode->next = temp;

}

void reverse(list *List){
    node *prev = NULL;
    node *curr = List->head;
    node *nxt = NULL;

    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    List->head = prev;
}

int traverse(list *List){
    int count = 0;
    node *temp = List->head;
    while(temp != NULL){
        count++;
        printf("%d->", temp->val);
        temp = temp->next;
    }

    printf("\n");
    return count;
}

int main(){
    list *List = init();
    add(List, 1);
    add(List, 2);
    add(List, 3);
    add(List, 4);
    add(List, 5);
    add(List, 6);
    add(List, 7);
    traverse(List);
    reverse(List);
    traverse(List);
    return 0;
}