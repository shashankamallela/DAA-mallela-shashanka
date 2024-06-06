#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to find the maximum number in a 2D array
int findMax(int **hats, int n) {
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; hats[i][j] != -1; j++) {
            if (hats[i][j] > max_val) {
                max_val = hats[i][j];
            }
        }
    }
    return max_val;
}

// Function to initialize the graph
void initializeGraph(int **hats, int n, int m, int **g) {
    for (int i = 0; i < m + 1; i++) {
        g[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; hats[i][j] != -1; j++) {
            int hat = hats[i][j];
            if (g[hat] == NULL) {
                g[hat] = (int *)malloc(n * sizeof(int));
                memset(g[hat], -1, n * sizeof(int));
            }
            for (int k = 0; k < n; k++) {
                if (g[hat][k] == -1) {
                    g[hat][k] = i;
                    break;
                }
            }
        }
    }
}

// Function to calculate the number of ways to assign hats
int numberWays(int **hats, int n) {
    int m = findMax(hats, n);
    
    // Allocate and initialize the graph
    int *g = (int *)malloc((m + 1) * sizeof(int *));
    initializeGraph(hats, n, m, g);
    
    // Allocate the DP table
    int *f = (int *)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i < m + 1; i++) {
        f[i] = (int *)malloc((1 << n) * sizeof(int));
        memset(f[i], 0, (1 << n) * sizeof(int));
    }
    f[0][0] = 1;

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            f[i][j] = f[i - 1][j];
            if (g[i] != NULL) {
                for (int k = 0; k < n && g[i][k] != -1; k++) {
                    int person = g[i][k];
                    if (j & (1 << person)) {
                        f[i][j] = (f[i][j] + f[i - 1][j ^ (1 << person)]) % MOD;
                    }
                }
            }
        }
    }

    // Get the result
    int result = f[m][(1 << n) - 1];

    // Free allocated memory
    for (int i = 0; i < m + 1; i++) {
        if (g[i] != NULL) {
            free(g[i]);
        }
    }
    free(g);

    for (int i = 0; i < m + 1; i++) {
        free(f[i]);
    }
    free(f);

    return result;
}

int main() {
    // Example input: list of hats liked by each person
    // Using -1 to indicate the end of the list for each person
    int *hats[] = {
        (int[]){3, 4, -1},
        (int[]){4, 5, -1},
        (int[]){5, -1}
    };
    int n = sizeof(hats) / sizeof(hats[0]);

    // Call the function and print the result
    int result = numberWays(hats, n);
    printf("Number of ways to assign hats: %d\n", result);

    return 0;
}
