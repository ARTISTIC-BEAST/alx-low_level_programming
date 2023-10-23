#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0; // Handle division by zero.
    }
}

int modulo(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        return 0; // Handle modulo by zero.
    }
}

int main() {
    // This is an example main function for testing the functions.
    int a = 10;
    int b = 2;
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, subtract(a, b));
    printf("%d * %d = %d\n", a, b, multiply(a, b));
    printf("%d / %d = %d\n", a, b, divide(a, b));
    printf("%d %% %d = %d\n", a, b, modulo(a, b));
    return 0;
}

