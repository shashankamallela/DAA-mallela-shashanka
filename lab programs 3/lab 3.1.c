#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 26
struct DSU {
    int *parent;
};
struct DSU* DSU_create(int n) {
    struct DSU* dsu = (struct DSU*)malloc(sizeof(struct DSU));
    dsu->parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        dsu->parent[i] = i;
    }
    return dsu;
}
int DSU_find(struct DSU* dsu, int x) {
    if (dsu->parent[x] != x) {
        dsu->parent[x] = DSU_find(dsu, dsu->parent[x]);
    }
    return dsu->parent[x];
}
void DSU_union(struct DSU* dsu, int x, int y) {
    int rootX = DSU_find(dsu, x);
    int rootY = DSU_find(dsu, y);
    if (rootX != rootY) {
        dsu->parent[rootY] = rootX;
    }
}

struct HashTable {
    int keys[MAX_CHARS];
    char values[MAX_CHARS][MAX_CHARS];
};

struct HashTable* HashTable_create() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    memset(ht->keys, -1, sizeof(ht->keys));
    return ht;
}

void HashTable_insert(struct HashTable* ht, char key, char* value) {
    int index = key - 'a';
    ht->keys[index] = key;
    strcpy(ht->values[index], value);
}
char* HashTable_get(struct HashTable* ht, char key) {
    int index = key - 'a';
    return ht->values[index];
}

char* smallestStringWithSwaps(char* s, int sSize, int** pairs, int pairsSize, int* pairsColSize) {
    struct DSU* dsu = DSU_create(sSize);
    for (int i = 0; i < pairsSize; ++i) {
        DSU_union(dsu, pairs[i][0], pairs[i][1]);
    }

    struct HashTable* groups = HashTable_create();
    for (int i = 0; i < sSize; ++i) {
        int root = DSU_find(dsu, i);
        char key = 'a' + root;
        if (HashTable_get(groups, key) == NULL) {
            char value[MAX_CHARS];
            strcpy(value, "");
            HashTable_insert(groups, key, value);
        }
        strcat(HashTable_get(groups, key), &s[i]);
    }

    char* result = (char*)malloc((sSize + 1) * sizeof(char));
    for (int i = 0; i < sSize; ++i) {
        int root = DSU_find(dsu, i);
        char key = 'a' + root;
        strcpy(result + i, HashTable_get(groups, key));
        DSU_union(dsu, i, root); 
    }
    result[sSize] = '\0';

    free(dsu->parent);
    free(dsu);
    free(groups);
    return result;
}

int main() {
    char s[] = "dcab";
    int pairs[][2] = {{0, 3}, {1, 2}};
    int sSize = sizeof(s) / sizeof(s[0]) - 1; 
    int pairsSize = sizeof(pairs) / sizeof(pairs[0]);
    int pairsColSize = sizeof(pairs[0]) / sizeof(pairs[0][0]);

    char* result = smallestStringWithSwaps(s, sSize, (int**)pairs, pairsSize, &pairsColSize);
    printf("Smallest string with swaps: %s\n", result);
    free(result);
    return 0;
}
