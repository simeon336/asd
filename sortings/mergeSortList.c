#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node * next; 
} node;

typedef struct list{
    struct node * head;
} list;


list* init(){
    list * List = (list*)malloc(sizeof(list));
    List->head = NULL;

    return List;
}

void addNode(list* List, int val){
    node *Node = (node*)malloc(sizeof(node));
    Node->value = val;

    if(List->head == NULL){
        List->head = Node;
        Node->next = NULL;
    }else{
        node *temp = List->head;
        List->head = Node;
        Node->next = temp;
    }
}

int main(){
    list *List = init();
    addNode(List,7);
    addNode(List,5);
    addNode(List,12);
    

    return 0;
}