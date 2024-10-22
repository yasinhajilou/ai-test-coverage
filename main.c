#include <stdio.h>
#include "calculator.h"

int main() {
    // Create a calculator instance
    Calculator calc = create_calculator();

    double a, b, result;
    int choice;

    // Loop to continuously perform operations until the user decides to exit
    while (1) {
        // Prompt the user for input
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);

        // Display operation choices
        printf("\nChoose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                result = calc.add(a, b);
                printf("Result: %.2f + %.2f = %.2f\n", a, b, result);
                break;
            case 2:
                result = calc.subtract(a, b);
                printf("Result: %.2f - %.2f = %.2f\n", a, b, result);
                break;
            case 3:
                result = calc.multiply(a, b);
                printf("Result: %.2f * %.2f = %.2f\n", a, b, result);
                break;
            case 4:
                if (b == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    result = calc.divide(a, b);
                    printf("Result: %.2f / %.2f = %.2f\n", a, b, result);
                }
                break;
            case 5:
                printf("Exiting the calculator.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n"); // Add a newline for better readability
    }

    return 0;
}
