/*
 * Sum of even Fibonacci numbers less than or equal to 4000000.
 */
#include <stdio.h>

long fib(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    long sum = 0;

    long f;
    int i;
    for (i = 1; (f = fib(i)) <= 4000000; i++) {
        if (f % 2 == 0) {
            sum += f;
        }
    }

    printf("%ld\n", sum);
}
