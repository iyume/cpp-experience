#include <stdio.h>

int getPositive(int x) {
    int mask = x >> (sizeof(int) * 8 - 1);
    return (x + mask) ^ mask;
}

int reset(int x, int mask) {
    return (x ^ mask) + (~mask + 1);
}

int main() {
    int x = -42;
    int result = getPositive(x);
    printf("Input: %d, Output: %d\n", x, result);

    x = 73;
    result = getPositive(x);
    printf("Input: %d, Output: %d\n", x, result);

    result = reset(42, -1);
    printf("Output: %d\n", result);

    result = reset(73, 0);
    printf("Output: %d\n", result);

    return 0;
}
