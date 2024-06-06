#include <stdio.h>
void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}
void sortArray(int arr[], int N) {
    int i = 0;
    while (i < N) {
        if (arr[i] == i + 1) {
            i++;
        }
        else {
            int temp1 = arr[i];
            int temp2 = arr[arr[i] - 1];
            arr[i] = temp2;
            arr[temp1 - 1] = temp1;
        }
    }
}
int main() {
    int arr[] = {2, 1, 5, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, N);
    printArray(arr, N);

    return 0;
}
