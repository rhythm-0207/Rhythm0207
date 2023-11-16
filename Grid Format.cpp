#include <iostream>
#include <array>
#include <vector>
#include <sstream>

// Size of the Sudoku grid
const int GRID_SIZE = 9;

// Typedef for a 9x9 Sudoku grid
using SudokuGrid = std::array<std::array<int, GRID_SIZE>, GRID_SIZE>;

// Function to convert string into Sudoku grid
SudokuGrid convertStringToSudoku(const std::string &str) 
{
    SudokuGrid grid;
    std::istringstream ss(str); // Create a string stream from the input string

    for (int i = 0; i < GRID_SIZE; ++i) 
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (!(ss >> grid[i][j]))
            {
                std::cerr << "Invalid input for Sudoku grid!" << std::endl;
                // If an error occurs, return an empty grid
                return {};
            }
        }
    }

    return grid;
}

// Function to display the Sudoku grid
void displaySudoku(const SudokuGrid &grid)
{
    std::cout << "{\n";
    for (const auto &row : grid)
    {
        std::cout << "    {";
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            std::cout << row[j];
            if (j != GRID_SIZE - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "},\n";
    }
    std::cout << "}\n";
}

int main()
{
    std::cout << "Enter the Sudoku puzzle row by row (9 rows):" << std::endl;

    std::string sudokuString;
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        std::string row;
        std::getline(std::cin, row);
        sudokuString += row + "\n";
    }

    SudokuGrid sudokuGrid = convertStringToSudoku(sudokuString);

    std::cout << "Converted Sudoku Grid:" << std::endl;
    displaySudoku(sudokuGrid);

    return 0;
}