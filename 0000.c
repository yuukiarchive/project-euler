/*
 * Sum of positive integers less than 1000 that are multiples of 3 or 5
 */
#include <stdio.h>

int main(void) {
    int sum = 0;
    int i;
    for (i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    printf("%d\n", sum);
}
