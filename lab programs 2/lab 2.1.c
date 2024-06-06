#include <stdio.h>
int main() {
    int number, revs_number = 0;
    printf("Enter a number to reverse: ");
    scanf("%d", &number);
    while (number > 0) {
        int remainder = number % 10;
        revs_number = (revs_number * 10) + remainder;
        number = number / 10;
    }
    printf("The reverse number is: %d\n", revs_number);
    return 0;
}
