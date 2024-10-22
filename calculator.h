#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef struct Calculator {
    double (*add)(double, double);
    double (*subtract)(double, double);
    double (*multiply)(double, double);
    double (*divide)(double, double);
} Calculator;

// Function prototypes to initialize the calculator
Calculator create_calculator();

#endif
