#include <stdio.h>
#include <stdlib.h>
typedef struct Pair {
    int index1;
    int index2;
} Pair;
Pair* createPair(int x, int y) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->index1 = x;
    pair->index2 = y;
    return pair;
}
void GetQuadruplets(int nums[], int len, int target) {
    Pair** map = (Pair*)malloc(len * sizeof(Pair));
    for (int i = 0; i < len; i++) {
        map[i] = NULL;
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int sum = nums[i] + nums[j];
            if (map[sum] == NULL) {
                Pair* pair = createPair(i, j);
                map[sum] = pair;
            }
        }
    }
    int count = 0;
    int** ans = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int lookUp = target - (nums[i] + nums[j]);
            if (lookUp >= 0 && lookUp < len && map[lookUp] != NULL) {
                Pair* pair = map[lookUp];
                if (pair->index1 != i && pair->index1 != j && pair->index2 != i && pair->index2 != j) {
                    ans[count] = (int*)malloc(4 * sizeof(int));
                    ans[count][0] = nums[pair->index1];
                    ans[count][1] = nums[pair->index2];
                    ans[count][2] = nums[i];
                    ans[count][3] = nums[j];
                    for (int k = 0; k < 4; k++) {
                        for (int l = k + 1; l < 4; l++) {
                            if (ans[count][k] > ans[count][l]) {
                                int temp = ans[count][k];
                                ans[count][k] = ans[count][l];
                                ans[count][l] = temp;
                            }
                        }
                    }
                    count++;
                }
            }
        }
    }
    for (int i = count - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
        free(ans[i]);
    }
    free(ans);
    free(map);
}
int main() {
    int arr[] = {1, 0, -1, 0, -2, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int K = 0;
    GetQuadruplets(arr, len, K);
    return 0;
}
