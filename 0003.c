/**
 * Largest prime factor of 600851475143.
 */
#include <stdio.h>

/*
 * An upper bound on the number of prime factors of n (with multiplicity)
 * Omega(n) is log_2 (n). `long long` is only guaranteed to go up to 2^63 - 1,
 * so 64 is sufficient.
 */
#define PRIME_FACTOR_BUFFER_SIZE 64

int factor(long long n, long long prime_factors[]) {
    int count = 0;

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
    long long prime_factors[PRIME_FACTOR_BUFFER_SIZE];
    int count = factor(600851475143LL, prime_factors);
    printf("%lld\n", prime_factors[count - 1]);
}
