#include <iostream>

int main() {
    char op;
    double num1, num2, result;

    // Input the numbers and operation
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    // Perform the operation
    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check if denominator is zero
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero!\n";
                return 1; // Exit the program with error status
            }
            break;
        default:
            std::cout << "Error: Invalid operation!\n";
            return 1; // Exit the program with error status
    }

    // Display the result
    std::cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << "\n";

    return 0; // Exit the program with success status
}

