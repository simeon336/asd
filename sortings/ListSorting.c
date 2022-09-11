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

node *find(list *List, int x){
    node *temp = List->head->next;
    while(temp != NULL){
        if(temp->val == x){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

node *findPrev(list *List, node *x){
    node *temp = List->head->next;
    if(temp = x){
        return List->head;
    }

    while(temp != NULL){
        if(temp->next == x){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void swap(list *List, int x, int y){
    node *xnode = find(List, x);
    node *ynode = find(List, y);

    if(xnode == List->head->next){
        node *yprev = List->head->next;
        while(yprev != NULL){
            if(yprev->next == ynode){
                break;
            }
            yprev = yprev->next;
        }
        node *xnext = xnode->next;
        node *ynext = ynode->next;
        yprev->next = xnode;
        xnext->next = ynode->next;
        ynode->next = xnext;

        List->head->next = ynode;
        return;
    }

    if(ynode == List->head->next){
        node *xprev = List->head->next;
        while(xprev != NULL){
            if(xprev->next == xnode){
                break;
            }
            xprev = xprev->next;
        }

        node *ynext = ynode->next;
        node *xnext = xnode->next;

        xprev->next = ynode;
        ynode->next = xnext;

        xnode->next = ynext;
        List->head->next = xnode;
        return;
    }

    node *yprev = List->head->next;
    while(yprev != NULL){
        if(yprev->next == ynode){
            break;
        }
        yprev = yprev->next;
    }

    node *xprev = List->head->next;
    while(xprev != NULL){
        if(xprev->next == xnode){
            break;
        }
        xprev = xprev->next;
    }

    node *xnext = xnode->next;
    node *ynext = ynode->next;

    yprev->next = xnode;
    xnode->next = ynext;
    
    xprev->next = ynode;
    ynode->next = xnext;

}

void sort(list *List){
    node *slow = List->head->next;
    node *fast = List->head->next;

    while(slow != NULL){
        printf("1");
        while(fast != NULL){
            printf("2");
            if(slow->val > fast->val){
                swap(List, slow->val, fast->val);
            }
            fast = fast->next;
        }
        slow = slow->next;
        fast = slow;
    }
}

int main(){
    list *List = init();
    add(List, 1);
    add(List, 6);
    add(List, 26);
    add(List, 2);
    add(List, 9);
    add(List, 12);
    sort(List);
    traverse(List);

    return 0;
}