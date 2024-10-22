#include <stdio.h>
#include <assert.h>
#include "calculator.h"

// Function to test addition
void test_add(Calculator calc) {
    assert(calc.add(2.0, 3.0) == 5.0);
    assert(calc.add(-2.0, 2.0) == 0.0);
    printf("Addition tests passed.\n");
}

// Function to test subtraction
void test_subtract(Calculator calc) {
    assert(calc.subtract(5.0, 3.0) == 2.0);
    assert(calc.subtract(3.0, 5.0) == -2.0);
    printf("Subtraction tests passed.\n");
}

// Function to test multiplication
void test_multiply(Calculator calc) {
    assert(calc.multiply(4.0, 2.0) == 8.0);
    assert(calc.multiply(-1.0, 5.0) == -5.0);
    printf("Multiplication tests passed.\n");
}

// Function to test division
void test_divide(Calculator calc) {
    assert(calc.divide(10.0, 2.0) == 5.0);
    assert(calc.divide(9.0, 3.0) == 3.0);
    printf("Division tests passed.\n");
}

int main() {
    Calculator calc = create_calculator();

    // Run all the tests
    test_add(calc);
    test_subtract(calc);
    test_multiply(calc);
    test_divide(calc);

    printf("All tests passed!\n");

    return 0;
}
