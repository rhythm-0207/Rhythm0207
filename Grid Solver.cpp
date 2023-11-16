#include <iostream>
#include <vector>

const int N = 9; // Size of the Sudoku grid

// Function to check if a number is safe to place in the given row and column
bool isSafe(std::vector<std::vector<int>> &grid, int row, int col, int num)
{
    // Check row and column constraints
    for (int i = 0; i < N; ++i)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return false;
        }
    }

    // Check 3x3 subgrid constraints
    int startRow = row - row % 3; // Starting row of the subgrid
    int startCol = col - col % 3; // Starting column of the subgrid

    for (int i = 0; i < 3; ++i) // this loop iterates over rows of the subgrid and the next one over columns
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i + startRow][j + startCol] == num) // if the number is already present in the subgrid, return false
            {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(std::vector<std::vector<int>> &grid) 
{
    int row, col;

    // Find an empty cell (with value 0)
    bool isEmpty = false;
    for (row = 0; row < N; ++row) // this loop iterates over rows of the grid and the next one over columns for each row
    {
        for (col = 0; col < N; ++col)
        {
            if (grid[row][col] == 0)
            {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
        {
            break;
        }
    }

    // If no empty cell is found, the puzzle is solved
    if (!isEmpty)
    {
        return true;
    }

    // Try placing a number from 1 to 9 in the empty cell
    for (int num = 1; num <= N; ++num)
    {
        if (isSafe(grid, row, col, num)) 
        {
            grid[row][col] = num; 

            // Recursively try to solve the puzzle
            if (solveSudoku(grid))
            {
                return true;
            }

            // If the number doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    return false; // No solution exists
}

// Function to display the solved Sudoku grid
void displayGrid(std::vector<std::vector<int>> &grid)
{
    for (const auto &row : grid) 
    {
        for (int num : row)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Define the input Sudoku grid
    std::vector<std::vector<int>> inputGrid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    if (solveSudoku(inputGrid))
    {
        std::cout << "Solved Sudoku Puzzle:" << std::endl;
        displayGrid(inputGrid);
    }
    else
    {
        std::cout << "No solution exists for the given Sudoku puzzle." << std::endl;
    }

    return 0;
}