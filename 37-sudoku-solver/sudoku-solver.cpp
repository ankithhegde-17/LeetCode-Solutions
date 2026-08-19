#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // Find an empty cell
                if (board[i][j] == '.') {
                    // Try digits from '1' to '9'
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Place the digit
                            
                            // Recursively try to solve the rest of the board
                            if (solve(board)) {
                                return true;
                            }
                            
                            // If it doesn't lead to a solution, backtrack
                            board[i][j] = '.';
                        }
                    }
                    // If no digit from '1'-'9' works, return false to trigger backtracking
                    return false;
                }
            }
        }
        // If no empty cells are left, the puzzle is solved
        return true;
    }

    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char c) {
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        
        for (int i = 0; i < 9; ++i) {
            // Check row
            if (board[row][i] == c) return false;
            // Check column
            if (board[i][col] == c) return false;
            // Check 3x3 sub-box
            if (board[boxRow + i / 3][boxCol + i % 3] == c) return false;
        }
        return true;
    }
};