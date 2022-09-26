#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node **items;
    int count;
    char visited;
} node;

node *create(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->count = 0;
    newNode->items = calloc(sizeof(node*), 1);
    newNode->visited = 0;

    return newNode;
}

void connect(node* a, node *b){
    if(a == NULL || b == NULL){
        return;
    }
   
    a->items = (node**)realloc(a->items, (1 + a->count)* sizeof(node*));
    a->items[a->count++] = b;
}



node *dfs(node *start, int val){
    if(start->val == val){
        return start;
    }

    start->visited = 1;

    for(int i = 0; i < start->count; i++){
        if(start->items[i]->visited == 1){
            continue;
        }

        node *temp = dfs(start->items[i], val);
        return temp;

        if(temp != NULL){
            start->visited = 0;
            return temp;
        }
    }
    
    start->visited = 0;
    return NULL;
}

void connectByNUm(node* start, int a, int b){
    node *parent = dfs(start, a);
    node *child = dfs(start, b);
    connect(parent, child);
}

void add(node *start, int parent, int val){
    node *temp = dfs(start, parent);
    node *newNode = create(val);
    connect(temp, newNode);
}

node* printDFS(node *start, int val){
    printf("%d, ", start->val);
    if(start->val == val){
        return start;
    }

    start->visited = 1;

    for(int i = 0; i < start->count; i++){
        if(start->items[i]->visited == 1){
            continue;
        }

        node *temp = dfs(start->items[i], val);
        printf("%d", temp->val);
        return temp;

        if(temp != NULL){
            start->visited = 0;
            return temp;
        }
    }
    
    start->visited = 0;
    return NULL;
}

int main(){
    node *n1 = create(0);
    add(n1, 0, 1);
    add(n1, 0, 2);
    add(n1, 1, 3);
    add(n1, 3, 4);
    add(n1, 4, 5);
    
    printf("%d", n1->items[0]->val);
    printf("%d", n1->items[1]->val);
    

    return 0;
}