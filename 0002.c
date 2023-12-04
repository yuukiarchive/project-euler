/**
 * Sum of even Fibonacci numbers less than or equal to 4000000.
 */
#include <stdio.h>

/**
 * Computes the `n`-th Fibonacci number.
 * @param n The index of the Fibonacci number to compute.
 * @return The `n`-th Fibonacci number.
 */
long fib(const int n) {
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

    long value;
    int i;
    for (i = 1; (value = fib(i)) <= 4000000; i++) {
        if (value % 2 == 0) {
            sum += value;
        }
    }

    printf("%ld\n", sum);
}
