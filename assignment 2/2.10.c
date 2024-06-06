#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;
StackNode* createNode(char value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
bool isEmpty(StackNode* root) {
    return root == NULL;
}
void push(StackNode** root, char value) {
    StackNode* newNode = createNode(value);
    newNode->next = *root;
    *root = newNode;
}
char pop(StackNode** root) {
    if (isEmpty(*root)) {
        return '\0';
    }
    StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}
bool areBracketsBalanced(char* expr) {
    StackNode* stack = NULL;
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&stack, expr[i]);
        } else {
            if (isEmpty(stack)) {
                return false;
            }
            char current_char = pop(&stack);
            if ((current_char == '(' && expr[i] != ')') ||
                (current_char == '{' && expr[i] != '}') ||
                (current_char == '[' && expr[i] != ']')) {
                return false;
            }
        }
    }
    return isEmpty(stack);
}
int main() {
    char expr[] = "{()}[]";
    if (areBracketsBalanced(expr)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
