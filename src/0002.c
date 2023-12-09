/**
 * @file
 * Sum of the even Fibonacci numbers less than or equal to 4000000.
 * https://projecteuler.net/problem=2
 */
#include <stdio.h>

long fib(const int);

int main(void) {
    long sum = 0;

    int i;
    long value;
    for (i = 1; (value = fib(i)) <= 4000000; i++) {
        if (value % 2 == 0) {
            sum += value;
        }
    }

    printf("%ld\n", sum);

    return 0;
}

/**
 * Computes the nth Fibonacci number, starting with 1 and 2.
 * @param n An integer >= 1.
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
