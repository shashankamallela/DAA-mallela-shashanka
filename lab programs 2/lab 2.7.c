#include <stdio.h>

int isInArray(int arr[], int len, int elem) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == elem) {
            return 1;
        }
    }
    return 0;
}
void getUnion(int a[], int n, int b[], int m) {
    int unionArray[n + m];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!isInArray(unionArray, k, a[i])) {
            unionArray[k++] = a[i];
        }
    }
    for (int i = 0; i < m; i++) {
        if (!isInArray(unionArray, k, b[i])) {
            unionArray[k++] = b[i];
        }
    }
    printf("Number of elements after union operation: %d\n", k);
    printf("The union set of both arrays is: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", unionArray[i]);
    }
    printf("\n");
}
int main() {
    int a[] = {1, 2, 5, 6, 2, 3, 5, 7, 3};
    int b[] = {2, 4, 5, 6, 8, 9, 4, 6, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    getUnion(a, n, b, m);

    return 0;
}
