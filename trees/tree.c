#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
} node;

node *add(node *root, int data){
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
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

void *treverse(node *root){
    if(root->left != NULL){
        treverse(root->left);
    }
    printf("%d, ", root->data);

    if(root->right != NULL){
        treverse(root->right);
    }
    
}

node* delete(node *root, int data){
    if(root->data = data){
        if(root->left == NULL && root->right == NULL){
            free(root);
        } else if(root->left != NULL || root->right != NULL){
            
        }

    }else if(data > root->data){
        delete(root->right, data);
    }else{
        delete(root->left, data);
    }
}

int main(){

    node *root = add(root, 6);
    add(root, 4);
    add(root, 5);
    add(root, 2);
    add(root, 8);
    add(root, 12);
    add(root, 7);
    add(root, 19);
    treverse(root);

    return 0;
}