#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *left, *right;
} node;

int isIdentical(node *root1, node *root2){
    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }
    return root1->val == root2->val && isIdentical(root1->left, root2->left)
     && isIdentical(root1->right, root2->right);
}

int isSubtree(node *root1, node *root2){
    if(root2 == NULL){
        return 1;
    }

    if(root1 == NULL){
        return 0;
    }
    if(root1->val < root2->val){
        return isSubtree(root1->right, root2);
    } else if(root1->val > root2->val){
        return isSubtree(root1->left, root2);
    } else{
        return
    }
}

int main(){
    return 0;
}