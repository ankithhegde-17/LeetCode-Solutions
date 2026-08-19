#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Arrays to track numbers 1-9 for each row, column, and 3x3 sub-box
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // Skip empty cells
                if (board[i][j] == '.') {
                    continue;
                }

                // Convert char digit ('1'-'9') to 0-indexed integer (0-8)
                int num = board[i][j] - '1';
                
                // Determine which 3x3 sub-box the cell belongs to (0 to 8)
                int boxIndex = (i / 3) * 3 + (j / 3);

                // If the number already exists in the current row, column, or sub-box, it's invalid
                if (row[i][num] || col[j][num] || box[boxIndex][num]) {
                    return false;
                }

                // Mark the number as seen in the respective row, column, and sub-box
                row[i][num] = true;
                col[j][num] = true;
                box[boxIndex][num] = true;
            }
        }

        // If no duplicates are found, the board configuration is valid
        return true;
    }
};