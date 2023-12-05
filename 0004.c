/**
 * Largest palindromic number that is the product of two 3-digit positive
 * integers.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_palindromic(const long);
char *ltoa(const long);
void strrev(char *);

int main(void) {
    long max_product = -1;

    int i;
    int j;
    long product;
    for (i = 100; i <= 999; i++) {
        for (j = 100; j <= 999; j++) {
            product = i * j;
            if (is_palindromic(product) && product > max_product) {
                max_product = product;
            }
        }
    }

    printf("%ld\n", max_product);
    return 0;
}

bool is_palindromic(const long n) {
    /* Converts `n` to a string. */
    const char *n_str = ltoa(n);

    /* Reverses `n_str`. */
    char *reversed = strdup(n_str);
    strrev(reversed);

    return strcmp(reversed, n_str) == 0;
}

char *ltoa(const long n) {
    const int length = snprintf(NULL, 0, "%ld", n);

    char *str = malloc(length + 1);
    snprintf(str, length + 1, "%ld", n);

    return str;
}

void strrev(char *str) {
    const int length = strlen(str);
    int i;
    int j;
    int tmp;
    for (i = 0; i < length / 2; i++) {
        j = length - i - 1;
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
