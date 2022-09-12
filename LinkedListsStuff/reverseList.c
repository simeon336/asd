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
    newList->head->next = NULL;
    return newList;
}

void add(list *List, int val){
    node *newNode = malloc(sizeof(node));
    newNode->val = val;

    if(List->head->next == NULL){
        List->head->next = newNode;
        newNode->next = NULL;
        return;
    }

    node *temp = List->head->next;
    List->head->next = newNode;
    newNode->next = temp;

}

list* reverse(list *List){
    node *prev = NULL;
    node *curr = List->head->next;
    node *nxt = NULL;

    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    List->head->next = prev;
    return List;
}

int traverse(list *List){
    int count = 0;
    node *temp = List->head->next;
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
    List = reverse(List);
    traverse(List);
    return 0;
}