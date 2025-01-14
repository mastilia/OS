#include <stdio.h>

int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

void main() {
    int a = 1, b = 2, c = 3;

    int result = add(&a, &b, &c);

    printf("Sum: %d\n", result);
}
