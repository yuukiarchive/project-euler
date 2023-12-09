/**
 * @file
 * Largest palindromic number that is the product of two 3-digit positive
 * integers.
 * https://projecteuler.net/problem=4
 */
#include <stdio.h>
#include <string.h>

/**
 * The size of the string buffer for the "ltoa" (long to ascii) conversion. The
 * maximum number of digits in a positive `long` is
 * D = floor(log10(LONG_MAX)) + 1. The buffer size must be >= D + 2, including
 * the minus sign and a terminating <code>'\0'</code>.
 *
 * FIXME: This should not be a fixed size.
 */
#define LTOA_BUFFER_SIZE 32

int is_palindromic(const long);
void reverse(char *);

int main(void) {
    long max_palindrome = -1;

    /*
     * Loops through 900^2 = 810000 numbers, the Cartesian square of 3-digit
     * numbers. This is inefficient. Even in case a Cartesian product is really
     * needed, something like `std::views::cartesian_product` in C++23 (or
     * `itertools.product` in Python) is more efficient than a nested `for`.
     */
    int i;
    int j;
    for (i = 100; i <= 999; i++) {
        for (j = 100; j <= 999; j++) {
            const long product = i * j;
            if (is_palindromic(product) && product > max_palindrome) {
                max_palindrome = product;
            }
        }
    }

    printf("%ld\n", max_palindrome);

    return 0;
}

/**
 * Determines if an integer is palindromic.
 * @param n An integer >= 0.
 */
int is_palindromic(const long n) {
    char str[LTOA_BUFFER_SIZE];
    char reversed[LTOA_BUFFER_SIZE];

    /* Converts the number to a string. */
    sprintf(str, "%ld", n);
    /*
     * Or, in C99:
     * const int length = snprintf(NULL, 0, "%ld", n);
     * char *str = malloc(length + 1);
     * sprintf(str, "%ld", n);
     * ...
     * free(str);
     */

    /* Duplicates the string and reverses it. */
    strcpy(reversed, str);
    reverse(reversed);

    /* Returns whether the reverse is equal to the original. */
    return strcmp(reversed, str) == 0;
}

/**
 * Reverses a string in-place.
 */
void reverse(char *str) {
    size_t length;
    size_t i;
    size_t j;

    /* If the string is empty, does nothing. */
    if (!*str) {
        return;
    }

    length = strlen(str);
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
