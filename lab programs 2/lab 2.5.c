#include <stdio.h>
int T(int n) {
 if (n == 1) {
 return 1; 
 } else {
 return 2 * T(n / 2) + n;
 }
}
int main() {
 int n = 16; 
 printf("T(%d) = %d\n", n, T(n));
 return 0;

