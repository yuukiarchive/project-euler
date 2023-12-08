/**
 * @file
 * Largest prime factor of 600851475143.
 * https://projecteuler.net/problem=3
 */
#include <stdio.h>
#include <stdint.h>

/**
 * The size of the array to store prime factors. For the number of prime factors
 * of a positive integer n (with multiplicity) Omega(n), it holds that Omega(n)
 * <= log_2 (n) because:
 *
 *     n = p_1 p_2 ... p_k >= 2*2*...*2 = 2^k,
 *
 * where k = Omega(n). Since a `int64_t` is only guaranteed to go up to 2^63 -
 * 1, the size of 64 is sufficient.
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
 * @param n The integer to factor, must be > 1.
 * @param prime_factors The array to store the prime factors of `n` in order
 * from smallest to largest.
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
