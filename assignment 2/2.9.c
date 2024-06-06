#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
int length(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void printList(Node* head) {
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
Node* deleteNthNodeFromEnd(Node* head, int n) {
    int Length = length(head);
    int nodeFromBeginning = Length - n + 1;
    Node* prev = NULL;
    Node* temp = head;

    for (int i = 1; i < nodeFromBeginning; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = head->next;
        return head;
    } else {
        prev->next = prev->next->next;
        return head;
    }
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printf("Linked List before Deletion:\n");
    printList(head);
    head = deleteNthNodeFromEnd(head, 4);
    printf("Linked List after Deletion:\n");
    printList(head);
    return 0;
}
