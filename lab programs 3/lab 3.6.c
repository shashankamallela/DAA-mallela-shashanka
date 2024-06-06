#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }
    
    int max_index = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[max_index]) {
            max_index = i;
        }
    }
    
    struct TreeNode* root = newTreeNode(nums[max_index]);
    
    root->left = constructMaximumBinaryTree(nums, max_index);
    root->right = constructMaximumBinaryTree(nums + max_index + 1, numsSize - max_index - 1);
    
    return root;
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    int nums[] = {3, 2, 1, 6, 0, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    struct TreeNode* root = constructMaximumBinaryTree(nums, numsSize);
    
    preorderTraversal(root);
    
    return 0;
}
