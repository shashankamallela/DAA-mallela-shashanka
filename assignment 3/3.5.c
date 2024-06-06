#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool existPathUtil(struct Node* root, int arr[], int n, int index) {
   
    if (!root || index == n) {
        return false;
    }

    if (!root->left && !root->right) {
        if (root->val == arr[index] && index == n - 1) {
            return true;
        }
        return false;
    }

    return ((index < n) && (root->val == arr[index]) &&
            (existPathUtil(root->left, arr, n, index + 1) ||
             existPathUtil(root->right, arr, n, index + 1)));
}


bool existPath(struct Node* root, int arr[], int n, int index) {
    if (!root) {
        return (n == 0);
    }
    return existPathUtil(root, arr, n, 0);
}
int main() {
    int arr[] = {5, 8, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->left->left->left = createNode(1);
    root->right->left = createNode(6);
    root->right->left->right = createNode(7);

    if (existPath(root, arr, n, 0)) {
        printf("Path Exists\n");
    } else {
        printf("Path does not Exist\n");
    }

    return 0;
}



