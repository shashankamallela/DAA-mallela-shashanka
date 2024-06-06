#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct Node {
    char* str;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
Node* createNode(char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->str = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(newNode->str, str);
    newNode->next = NULL;
    return newNode;
}
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
void enqueue(Queue* queue, char* str) {
    Node* newNode = createNode(str);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}
Node* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return temp;
}
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}
char** letterCombinationsUtil(int number[], int n, char* table[], int* returnSize) {
    Queue* queue = createQueue();
    enqueue(queue, "");
    int maxCombinations = MAX;
    char** result = (char*)malloc(maxCombinations * sizeof(char));
    *returnSize = 0;
    while (!isQueueEmpty(queue)) {
        Node* node = dequeue(queue);
        char* s = node->str;

        if (strlen(s) == n) {
            result[returnSize] = (char)malloc((strlen(s) + 1) * sizeof(char));
            strcpy(result[*returnSize], s);
            (*returnSize)++;
        } else {
            int digit = number[strlen(s)];
            for (int i = 0; i < strlen(table[digit]); i++) {
                char* newCombination = (char*)malloc((strlen(s) + 2) * sizeof(char));
                strcpy(newCombination, s);
                newCombination[strlen(s)] = table[digit][i];
                newCombination[strlen(s) + 1] = '\0';
                enqueue(queue, newCombination);
                free(newCombination);
            }
        }
        free(s);
        free(node);
    }
    return result;
}
void letterCombinations(int number[], int n) {
    char* table[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int returnSize;
    char** list = letterCombinationsUtil(number, n, table, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s ", list[i]);
        free(list[i]);
    }
    printf("\n");

    free(list);
}
int main() {
    int number[] = {2, 3};
    int n = sizeof(number) / sizeof(number[0]);
    letterCombinations(number, n);
    return 0;
}
