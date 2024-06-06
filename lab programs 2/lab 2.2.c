#include <stdio.h>
int main() {
    int Input_Number = 78;
    int Sum = 0;
    for (int i = 1; i < Input_Number; i++) {
        if (Input_Number % i == 0) {
            Sum += i;
        }
    }
    if (Sum == Input_Number) {
        printf("Number is a Perfect Number.\n");
    } else {
        printf("Number is not a Perfect Number.\n");
    }

    return 0;
}
