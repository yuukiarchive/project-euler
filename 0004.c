/**
 * @file
 * Largest palindromic number that is the product of two 3-digit positive
 * integers.
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindromic(const long);
void reverse(char *);

int main(void) {
    long max_palindrome = -1;

    /*
     * Loops through 900^2 = 810000 numbers, the Cartesian square of 3-digit
     * numbers. This is inefficient. Even in case a Cartesian product is really
     * needed, `std::views::cartesian_product` in C++23 (or `itertools.product`
     * in Python), for example, is more efficient than a nested `for`.
     */
    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            const long product = i * j;
            if (is_palindromic(product) && product > max_palindrome) {
                max_palindrome = product;
            }
        }
    }

    printf("%ld\n", max_palindrome);
}

/**
 * Determines if an integer is palindromic.
 * @param n An integer >= 0.
 */
bool is_palindromic(const long n) {
    /* Converts `n` to a string. */
    char str[12];
    snprintf(str, 12, "%ld", n);

    /* Duplicates and reverses the string. */
    char reversed[12];
    strcpy(reversed, str);
    reverse(reversed);

    /* Returns whether the reverse of `n` is equal to `n`. */
    return strcmp(reversed, str) == 0;
}

/**
 * Reverses a string in-place.
 */
void reverse(char *str) {
    /* If the string is empty, does nothing. */
    if (!*str) {
        return;
    }

    const size_t length = strlen(str);
    for (size_t i = 0, j = length - 1; i < j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
