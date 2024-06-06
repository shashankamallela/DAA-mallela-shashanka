#include <stdio.h>
#include <string.h>

int getNumber(const char* word) {
    int num = 0;
    for (int i = 0; i < strlen(word); i++)
        num = num * 10 + (word[i] - 'a');
    return num;
}

int isSumEqual(const char* firstWord, const char* secondWord, const char* targetWord) {
    int first = getNumber(firstWord);
    int second = getNumber(secondWord);
    int target = getNumber(targetWord);
    return first + second == target;
}

int main() {
    const char* firstWord = "example";
    const char* secondWord = "words";
    const char* targetWord = "sum";
    if (isSumEqual(firstWord, secondWord, targetWord))
        printf("The sum is equal.\n");
    else
        printf("The sum is not equal.\n");
    return 0;
}
