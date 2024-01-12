// By: mathewn24

// Client flie which performs the program flow.
#include <iostream>
#include "RushHour.h"

int main() {

    int car, step, row = 0, col = 0;
    std::string inputGrid[6];
    int validMove, totalSteps;
    bool gameOver = false;

    // Get string input from user.
    std::cout << "Enter initial grid: ";
    for (int i = 0; i < 6; i++) {
        std::cin >> inputGrid[i];
    }

    // Create a RushHour object and initialise with user input.
    RushHour game(inputGrid);

    // Create game over condition to run the game loop.
    while (!gameOver) {
        // Print game board.
        game.print();

        // Loop to validate user input until a valid move is made.
        while (true) {
            std::cout << "Move a car: ";
            std::cin >> car >> step;
            validMove = game.moveCar(car, step);
            if (validMove == 0){
                break;
            } else if (validMove == 1) {
                std::cout << "Invalid car or step! Try again." << std::endl;
            } else if (validMove == 2) {
                std::cout << "Hit! Try again." << std::endl;
            }
        }

        totalSteps = game.getTotalSteps();
        gameOver = game.isSolved();

        // Only if the game is over and there is less than 100 step the player wins.
        if (gameOver && totalSteps < 100) {
            std::cout << "Congrats! You finished in " << totalSteps << " steps." << std::endl;
            break;

        // If the player has more than 100 steps they lose the game.
        } else if (!gameOver && totalSteps > 100){
            std::cout << "Oops! You could not solve in 100 steps." << std::endl;
            break;
        }
    }

    return 0;
}
