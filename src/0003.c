/**
 * @file
 * Largest prime factor of 600851475143.
 * https://projecteuler.net/problem=3
 */
#include <stdint.h>
#include <stdio.h>

/**
 * The size of the array to store prime factors. We have Omega(n) <= log2(n),
 * where Omega(n) is the number of prime factors (including duplicates) of a
 * positive integer n, because:
 *
 *     n = p_1 p_2 ... p_k >= 2*2*...*2 = 2^k,
 *
 * where k = Omega(n). Since the maximum value of an `int64_t` is exactly
 * 2^63 - 1, a size of 64 is sufficient.
 */
#define MAX_PRIME_FACTOR_COUNT 64

int factor(int64_t, int64_t[]);

int main(void) {
    int64_t prime_factors[MAX_PRIME_FACTOR_COUNT];

    /* Factors 600851475143. */
    const int count = factor(600851475143, prime_factors);

    /* FIXME: No portable way to print an `int64_t`. */
    printf("%ld\n", (long)prime_factors[count - 1]);

    return 0;
}

/**
 * Factors an integer into primes.
 * @param n An integer > 1.
 * @param prime_factors An array to store the prime factors of `n`. The results
 * are in order from smallest to largest.
 * @return The number of prime factors of `n`.
 */
int factor(int64_t n, int64_t prime_factors[]) {
    int count = 0;

    /* Performs trial division by the integers from 2 to `n` - 1. */
    int64_t i;
    for (i = 2; i < n; i++) {
        while (n % i == 0) {
            prime_factors[count++] = i;
            n /= i;
        }
    }

    if (n != 1) {
        prime_factors[count++] = n;
    }

    return count;
}
