// By: mathewn24

#include <iostream>
#include "RushHour.h"

RushHour::RushHour(std::string g[]) : totalSteps(0) {
    grid[0] = "########";
    grid[1] = g[0];
    grid[2] = g[1];
    grid[3] = g[2];
    grid[4] = g[3];
    grid[5] = g[4];
    grid[6] = g[5];
    grid[7] = "########";
}

bool RushHour::locateCar(int car, int &row, int &col) const{
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if (grid[i][j] == car + '0') {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

int RushHour::moveCar(int car, int step){ // non-const
    int row, col, abs_step;
    bool vertical, empty;
    bool carExists = locateCar(car, row, col);
    int h_length = 0, v_length = 0;
    
    // Get absolute value of steps for future use.
    if (step < 0) {
        abs_step = (-1)*step; 
    } else {
        abs_step = step;
    }
    
    if (step == 0 || !carExists) {
        return 1;

    } else { // If car exists, check if car is vertical or horizontal.
        
        if (grid[row][col] == grid[row][col+1]) {
            vertical = false;
        } else if (grid[row][col] == grid[row+1][col]) {
            vertical = true;
        }

        // Positive value for step is moving down or right.
        // Negative value for step is moving up or left.
        if (vertical) {
            // Traverse down to find the car's length.
            while (grid[row + v_length][col] == car + '0') {
                v_length++;
            }
    
            if (step < 0) {
                // Check if there are empty cells for the number of cells.
                for (int i = 1; i < abs_step; i++) {
                    if (grid[row-1-i][col] != '.') {
                        return 2;
                    }
                }
                
                // If they are empty, update value and return 0.
                for (int i = 0; i < abs_step; i++) {
                    grid[row-1-i][col] = '0' + car;
                    grid[row-1+v_length-i][col] = '.';
                }

                // Update the number of total steps and return 0.
                totalSteps += abs_step;
                return 0;

            } else if (step > 0) {
                // Check if there are empty cells for the number of cells.
                for (int i = 0; i < abs_step; i++) {
                    if (grid[row+v_length+i][col] != '.') {
                        return 2;
                    }
                }

                // If they are empty, update value.
                for (int i = 0; i < abs_step; i++) {
                    grid[row+v_length+i][col] = '0' + car;
                    grid[row+i][col] = '.';
                }

                // Update the number of total steps and return 0.
                totalSteps += abs_step;
                return 0;
            }
            
        } else if (!vertical){
            // Traverse right to find the car's length.
            while (grid[row][col + h_length] == car + '0') {
                h_length++;
            }

            if (step < 0) {
                // Check if there are empty cells for the number of cells.
                for (int i = 1; i < abs_step; i++) {
                    if (grid[row][col-1-i] != '.') {
                        return 2;
                    }
                }
                
                // If they are empty, update value and return 0.
                for (int i = 0; i < abs_step; i++) {
                    grid[row][col-1-i] = '0' + car;
                    grid[row][col-1+h_length-i] = '.';
                }

                // Update the number of total steps and return 0.
                totalSteps += abs_step;
                return 0;

            } else if (step > 0) {
                // Check if there are empty cells for the number of cells.
                for (int i = 0; i < abs_step; i++) {
                    if (grid[row][col+h_length+i] != '.') {
                        return 2;
                    }
                }

                // If they are empty, update value and return 0.
                for (int i = 0; i < abs_step; i++) {
                    grid[row][col+h_length+i] = '0' + car;
                    grid[row][col+i] = '.';
                }

                // Update the number of total steps and return 0.
                totalSteps += abs_step;
                return 0;
            }
        }
    }
    return 20;
}

bool RushHour::isSolved() const{
    if (grid[3][7] == '0') {
        return true;
    }
    return false;
}

int RushHour::getTotalSteps() const{
    return totalSteps;
}

void RushHour::print() const{
    for (int i = 0; i < 8; i++) {
        std::cout << grid[i] << std::endl;
    }
    int steps = getTotalSteps();
    std::cout << "Steps: " << steps << std::endl;
}