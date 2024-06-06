#include <stdio.h>
void segregateEvenOdd(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (arr[left] % 2 == 0 && left < right) {
            left++;
        }
        while (arr[right] % 2 == 1 && left < right) {
            right--;
        }
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}
int main() {
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    segregateEvenOdd(arr, n);
    printf("Array after segregation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
