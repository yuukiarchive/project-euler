/**
 * Largest prime factor of 600851475143.
 */
#include <stdio.h>

/**
 * The size of the array to store prime factors. Let Omega(n) be the number of
 * prime factors of n (with repetition). Then Omega(n) <= log_2 (n) because:
 *     n = p_1 p_2 ... p_i >= 2*2*...*2 = 2^Omega(n).
 * Since `long long` is only guaranteed to go up to 2^63 - 1, the size of 64 is
 * sufficient.
 */
#define MAX_PRIME_FACTOR_COUNT 64

/**
 * Factors `n` into primes.
 * @param n The positive integer to factor.
 * @param prime_factors The array to store prime factors.
 * @return The number of prime factors of `n`.
 */
int factor(long long n, long long prime_factors[]) {
    int count = 0;

    /* Performs trial division by the integers from 2 to n - 1. */
    long long i;
    for (i = 2; i < n; i++) {
        while (n % i == 0) {
            prime_factors[count] = i;
            count++;
            n /= i;
        }
    }

    if (n != 1) {
        prime_factors[count] = n;
        count++;
    }

    return count;
}

int main(void) {
    long long prime_factors[MAX_PRIME_FACTOR_COUNT];
    const int count = factor(600851475143, prime_factors);
    printf("%lld\n", prime_factors[count - 1]);
}
