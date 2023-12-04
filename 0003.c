#include <stdio.h>

#define BUFFER_SIZE 1024

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
    long long prime_factors[BUFFER_SIZE];
    int count = factor(600851475143LL, prime_factors);
    printf("%lld\n", prime_factors[count - 1]);
}
