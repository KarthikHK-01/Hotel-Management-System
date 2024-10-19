#include <stdio.h>
#include <stdlib.h>
// Define a structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
int arr[50];
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to convert a sorted array to a binary search tree
struct TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct TreeNode* root = createNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}
int j=0;
void inOrderTraversal(struct TreeNode* root) {
    
    if (root != NULL) {
        inOrderTraversal(root->left);
        arr[j++]=root->data;
        inOrderTraversal(root->right);
    }
}