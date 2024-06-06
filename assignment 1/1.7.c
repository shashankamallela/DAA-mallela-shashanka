#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 1000
struct Node {
    int data;
    struct Node* next;
};
struct HashSet {
    struct Node* table[TABLE_SIZE];
};
int reversed(int num) {
    int ans = 0;
    while (num > 0) {
        ans = ans * 10 + num % 10;
        num /= 10;
    }
    return ans;
}
struct HashSet* HashSet_create() {
    struct HashSet* set = (struct HashSet*)malloc(sizeof(struct HashSet));
    for (int i = 0; i < TABLE_SIZE; i++) {
        set->table[i] = NULL;
    }
    return set;
}

int hash(int num) {
    return abs(num) % TABLE_SIZE;
}
void HashSet_insert(struct HashSet* set, int num) {
    int index = hash(num);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = set->table[index];
    set->table[index] = newNode;
}
int HashSet_contains(struct HashSet* set, int num) {
    int index = hash(num);
    struct Node* current = set->table[index];
    while (current != NULL) {
        if (current->data == num) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int countDistinctIntegers(int* nums, int numsSize) {
    struct HashSet* numsSet = HashSet_create();

    for (int i = 0; i < numsSize; i++) {
        HashSet_insert(numsSet, nums[i]);
        HashSet_insert(numsSet, reversed(nums[i]));
    }

    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = numsSet->table[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }
    return count;
}
int main() {
    int nums[] = {123, 456, 789};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Number of distinct integers: %d\n", countDistinctIntegers(nums, numsSize));
    return 0;
}
