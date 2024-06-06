#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int within_two_edits(char *word1, char *word2) {
    int count_diff = 0;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (abs(len1 - len2) > 2) {
        return 0;
    }
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (word1[i] != word2[j]) {
            count_diff++;
            if (count_diff > 2) {
                return 0; 
            }
            if (len1 > len2) {
                i++;
            } else if (len1 < len2) {
                j++;
            } else {
                i++;
                j++;
            }
        } else {
            i++;
            j++;
        }
    }
    return 1; 
}

char** words_within_two_edits(char** queries, int queriesSize, char** dictionary, int dictSize, int* returnSize) {
    char** result = (char*)malloc(queriesSize * sizeof(char));
    *returnSize = 0;
    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < dictSize; j++) {
            if (within_two_edits(queries[i], dictionary[j])) {
                result[*returnSize] = strdup(queries[i]); 
                (*returnSize)++;
                break;
            }
        }
    }
    return result;
}

int main() {
    char *queries[] = {"word", "world", "wold"};
    int queriesSize = sizeof(queries) / sizeof(queries[0]);
    char *dictionary[] = {"word", "work", "world", "wold", "wild"};
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);
    int returnSize;
    char **result = words_within_two_edits(queries, queriesSize, dictionary, dictSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]); 
    }
    free(result); 
    return 0;
}
