/**
 * @file
 * Sum of the positive integers less than 1000 that are divisible by 3 or 5.
 */
#include <stdio.h>

int main(void) {
    /*
     * An `int` is only guaranteed to go up to 2^15 - 1 = 32767, which is not
     * enough. A `long` is guaranteed to go up to 2^31 - 1 = 2147483647, which
     * is sufficient since it is even greater than 1 + 2 + ... + 999 =
     * 999*1000/2 = 499500.
     */
    long sum = 0;

    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("%ld\n", sum);
}
