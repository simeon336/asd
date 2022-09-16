#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

typedef struct node{
    int val;
    struct node *left, *right;
} node;



node *add(node *root, int val){
    if(root == NULL){
        node *newNode = malloc(sizeof(node));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return root;
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

node* binSearch(node *root, int *arr, size_t size){
    printf("----\n");
    int middle_index = size / 2;
    int middle = arr[middle_index];
    
    root = add(root, middle);
    
    if (size == 1) {
        return root;
    }

    binSearch(root, arr, middle_index);
    int right_side_length_is_even = size%2;
    binSearch(root, arr+(middle_index)+right_side_length_is_even, size/2);
    return root;
}

int main(){
    node *root;
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    root = binSearch(NULL, arr, sizeof(arr)/sizeof(arr[0]));
    traverse(root, 0, 0, 0);
    return 0;
}
