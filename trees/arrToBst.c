#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *left, *right;
} node;

node *add(node *root, int val){
    if(root == NULL){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
    }

    if(val > root->val){
        root->right = add(root->right, val);
        
    } else if(val < root->val){
        root-> left = add(root->left, val);
    }
    return root;
}

void traverse(node *root, int parent_value, int is_left, int depth){
    
    printf("depth: %d, parent: %d, is_left: %d, val: %d\n", depth, parent_value, is_left, root->val);

    if(root->left != NULL){
        traverse(root->left, root->val, 1, depth +  1);
    }

    if(root->right != NULL){
        traverse(root->right, root->val, 0, depth + 1);
    }
}

void arrToBST(int *arr, int size){
    int middle = size/2;
    node *root = add(NULL, arr[middle]);
    for(int i = 0; i < 6; i+=2){
        if(i != middle){
            add(root, arr[i]);
        }
    }

    for(int i = 1; i < 6; i+=2){
        if(i != middle){
            add(root, arr[i]);
        }
    }
    traverse(root, 0, 0, 0);
}


int main(){
    int arr[6] = {1, 2, 3, 4, 5, 6};
    arrToBST(arr, 6);
    return 0;
}