#include <stdio.h>
int maxArea(int A[], int Len) {
    int area = 0;
    for (int i = 0; i < Len; i++) {
        for (int j = i + 1; j < Len; j++) {
            int height = (A[i] < A[j]) ? A[i] : A[j];
            int width = j - i;
            int current_area = height * width;
            if (current_area > area) {
                area = current_area;
            }
        }
    }
    return area;
}
int main() {
    int a[] = { 1, 5, 4, 3 };
    int b[] = { 3, 1, 2, 4, 5 };
    int len1 = sizeof(a) / sizeof(a[0]);
    int len2 = sizeof(b) / sizeof(b[0]);

    printf("%d\n", maxArea(a, len1));
    printf("%d\n", maxArea(b, len2));
    return 0;
}
