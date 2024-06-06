#include <stdio.h>
void getUnion(int a[], int n, int b[], int m) {
    int unionArray[n + m];
    int k = 0;
    for (int i = 0; i < n; i++) {
        int exists = 0;
        for (int j = 0; j < k; j++) {
            if (unionArray[j] == a[i]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            unionArray[k++] = a[i];
        }
    }
    for (int i = 0; i < m; i++) {
        int exists = 0;
        for (int j = 0; j < k; j++) {
            if (unionArray[j] == b[i]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
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
