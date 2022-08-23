#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
} node;

node *add(node *root, int data){
    if(root == NULL){
        root = (node*)malloc(sizeof(node*));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }

    if(root->data < data){ //sluchai otdqsno
        root->right = add(root->right, data);
    } else if(root->data > data){ //sluchai lqvo
       root->left = add(root->left, data);
    }

    return root;
};

int main(){

    node *root = add(root, 6);
    add(root, 4);
    add(root, 8);
    printf("Root: %d\n", root->data);
    printf("Left: %d\n", root->left->data);
    printf("Right: %d\n", root->right->data);

    return 0;
}