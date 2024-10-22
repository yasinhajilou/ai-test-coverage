#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

// Define the add function
double add(double a, double b) {
    return a + b;
}

// Define the subtract function
double subtract(double a, double b) {
    return a - b;
}

// Define the multiply function
double multiply(double a, double b) {
    return a * b;
}

// Define the divide function
double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return a / b;
}

// Function to initialize the Calculator "class"
Calculator create_calculator() {
    Calculator calc;
    calc.add = add;
    calc.subtract = subtract;
    calc.multiply = multiply;
    calc.divide = divide;
    return calc;
}
