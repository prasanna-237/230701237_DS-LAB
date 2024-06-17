#include <stdio.h>
#include <stdlib.h>
 

structBinaryTreeNode {
    intkey;
    structBinaryTreeNode *left, *right;
};
 
structBinaryTreeNode* newNodeCreate(intvalue)
{
    structBinaryTreeNode* temp
        = (structBinaryTreeNode*)malloc(
            sizeof(structBinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    returntemp;
}
 

structBinaryTreeNode*
searchNode(structBinaryTreeNode* root, inttarget)
{
    if(root == NULL || root->key == target) {
        returnroot;
    }
    if(root->key < target) {
        returnsearchNode(root->right, target);
    }
    returnsearchNode(root->left, target);
}
 
structBinaryTreeNode*
insertNode(structBinaryTreeNode* node, intvalue)
{
    if(node == NULL) {
        returnnewNodeCreate(value);
    }
    if(value < node->key) {
        node->left = insertNode(node->left, value);
    }
    elseif(value > node->key) {
        node->right = insertNode(node->right, value);
    }
    returnnode;
}
 
voidpostOrder(structBinaryTreeNode* root)
{
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}
 

voidinOrder(structBinaryTreeNode* root)
{
    if(root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}
 
voidpreOrder(structBinaryTreeNode* root)
{
    if(root != NULL) {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
structBinaryTreeNode* findMin(structBinaryTreeNode* root)
{
    if(root == NULL) {
        returnNULL;
    }
    elseif(root->left != NULL) {
        returnfindMin(root->left);
    }
    returnroot;
}
structBinaryTreeNode* delete(structBinaryTreeNode* root,
                               intx)
{
    if(root == NULL)
        returnNULL;
 
    if(x > root->key) {
        root->right = delete(root->right, x);
    }
    elseif(x < root->key) {
        root->left = delete(root->left, x);
    }
    else{
        if(root->left == NULL && root->right == NULL) {
            free(root);
            returnNULL;
        }
        elseif(root->left == NULL
                 || root->right == NULL) {
            structBinaryTreeNode* temp;
            if(root->left == NULL) {
                temp = root->right;
            }
            else{
                temp = root->left;
            }
            free(root);
            returntemp;
        }
        else{
            structBinaryTreeNode* temp
                = findMin(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }
    returnroot;
}
 
intmain()
{
    
    structBinaryTreeNode* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    if(searchNode(root, 60) != NULL) {
        printf("60 found");
    }
    else{
        printf("60 not found");
    }
 
    printf("\n");
 
    
    postOrder(root);
    printf("\n");
 
    
    preOrder(root);
    printf("\n");
 
    
    inOrder(root);
    printf("\n");
 
    )
    structBinaryTreeNode* temp = delete(root, 70);
    printf("After Delete: \n");
    inOrder(root);
 
 
    return0;
}
