#include <stdio.h>
#include <stdbool.h>

int countElements(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int xPlusOne = x + 1;
        bool found = false;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == xPlusOne) {
                found = true;
                break;
            }
        }
        
        int k = i - 1;
        while (found == false && k >= 0) {
            if (arr[k] == xPlusOne) {
                found = true;
                break;
            }
            k--;
        }
    
        if (found == true) {
            count++;
        }
    }
    
    return count;
}
int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", countElements(arr, n));
    
    return 0;
}



