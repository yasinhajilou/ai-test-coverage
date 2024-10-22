#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../calculator.h"

// Function to test division by zero
void test_divide_by_zero(Calculator calc) {
    int caught_error = 0;
    // Redirect stderr to capture the division by zero error message
    FILE *original = stderr;
    FILE *temp = fopen("temp.txt", "w");
    if (temp) {
        stderr = temp;
    }
    
    // Attempt to divide by zero
    calc.divide(1.0, 0.0);
    
    // Check if the error message was printed
    fflush(stderr);
    if (temp) {
        fclose(temp);
        stderr = original;
        FILE *file = fopen("temp.txt", "r");
        if (file) {
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), file)) {
                if (strstr(buffer, "Error: Division by zero") != NULL) {
                    caught_error = 1;
                }
            }
            fclose(file);
            remove("temp.txt");
        }
    }
    
    assert(caught_error == 1);
    printf("Division by zero test passed.\n");
}

int main() {
    Calculator calc = create_calculator();

    // Run all the tests
    test_divide_by_zero(calc); // Run the division by zero test

    printf("All tests passed!\n");

    return 0;
}