#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with current time
    srand(time(0)); 

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1; 

    // Initialize variables
    int guess;
    int attempts = 0;

    // Greet the player
    std::cout << "\t\tYo, welcome to the Guessing Game!\n\n";
    std::cout << "\tI've got a number in mind between 1 and 100. Try to guess it!\n\n";

    // Start the guessing loop
    do {
        // Prompt the player for their guess
        std::cout << "Go on, take a shot: ";
        std::cin >> guess;
        attempts++;

        // Check if the guess is correct, too low, or too high
        if (guess == randomNumber) {
            std::cout << "Bingo! You nailed it in " << attempts << " tries!\n";
        } else if (guess < randomNumber) {
            std::cout << "Nah, too low! Give it another go.\n";
        } else {
            std::cout << "Whoa, too high! Try again.\n";
        }
    } while (guess != randomNumber);

    return 0;
}

