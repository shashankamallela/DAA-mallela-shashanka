#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void to_difference_array(char *word, int *diff_array) {
    int length = strlen(word);
    for (int i = 0; i < length - 1; i++) {
        diff_array[i] = word[i + 1] - word[i];
    }
}

char* odd_string_difference(char** words, int wordsSize) {
    int *difference_arrays = (int *)malloc(wordsSize * sizeof(int *));
    for (int i = 0; i < wordsSize; i++) {
        difference_arrays[i] = (int *)malloc((strlen(words[i]) - 1) * sizeof(int));
        to_difference_array(words[i], difference_arrays[i]);
    }
    int *difference_count = (int *)calloc(wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        int *diff_array = difference_arrays[i];
        int diff_array_size = strlen(words[i]) - 1;
        int diff_hash = 0;
        for (int j = 0; j < diff_array_size; j++) {
            diff_hash += diff_array[j];
        }
        difference_count[diff_hash]++;
    }
    int *odd_diff_array;
    for (int i = 0; i < wordsSize; i++) {
        int *diff_array = difference_arrays[i];
        int diff_array_size = strlen(words[i]) - 1;
        int diff_hash = 0;
        for (int j = 0; j < diff_array_size; j++) {
            diff_hash += diff_array[j];
        }
        if (difference_count[diff_hash] == 1) {
            odd_diff_array = diff_array;
            break;
        }
    }
    char *result = NULL;
    for (int i = 0; i < wordsSize; i++) {
        int *diff_array = difference_arrays[i];
        if (memcmp(diff_array, odd_diff_array, (strlen(words[i]) - 1) * sizeof(int)) == 0) {
            result = words[i];
            break;
        }
    }
    for (int i = 0; i < wordsSize; i++) {
        free(difference_arrays[i]);
    }
    free(difference_arrays);
    free(difference_count);

    return result;
}

int main() {
    char *words[] = {"abc", "bcd", "ace"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    printf("%s\n", odd_string_difference(words, wordsSize));
    return 0;
}
