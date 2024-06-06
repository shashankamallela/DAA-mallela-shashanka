#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    int* data;
    struct Node* next;
};
struct ZigzagIterator {
    struct Node* head;
};
struct ZigzagIterator* ZigzagIterator_create(int* v1, int v1Size, int* v2, int v2Size) {
    struct ZigzagIterator* iterator = (struct ZigzagIterator*)malloc(sizeof(struct ZigzagIterator));
    iterator->head = NULL;

    if (v1Size > 0) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = v1;
        node->next = NULL;
        if (iterator->head == NULL) {
            iterator->head = node;
        } else {
            struct Node* current = iterator->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    }

    if (v2Size > 0) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = v2;
        node->next = NULL;
        if (iterator->head == NULL) {
            iterator->head = node;
        } else {
            struct Node* current = iterator->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    }

    return iterator;
}

int ZigzagIterator_next(struct ZigzagIterator* iterator) {
    struct Node* node = iterator->head;
    int value = *(node->data);
    node->data++;
    iterator->head = node->next;
    return value;
}

bool ZigzagIterator_hasNext(struct ZigzagIterator* iterator) {
    return iterator->head != NULL;
}

void ZigzagIterator_destroy(struct ZigzagIterator* iterator) {
    struct Node* current = iterator->head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    free(iterator);
}

int main() {
    int v1[] = {1, 2};
    int v1Size = sizeof(v1) / sizeof(v1[0]);
    int v2[] = {3, 4, 5, 6};
    int v2Size = sizeof(v2) / sizeof(v2[0]);

    struct ZigzagIterator* iterator = ZigzagIterator_create(v1, v1Size, v2, v2Size);
    while (ZigzagIterator_hasNext(iterator)) {
        printf("%d ", ZigzagIterator_next(iterator));
    }
    printf("\n");

    ZigzagIterator_destroy(iterator);

    return 0;
}
