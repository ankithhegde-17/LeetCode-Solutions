#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, int> rowMasks;
        
        // Map each row to a bitmask of its reserved seats
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            rowMasks[row] |= (1 << col);
        }

        // Rows with no reservations can each fit the maximum of 2 groups
        long long totalGroups = (long long)(n - rowMasks.size()) * 2;

        // Check each row that has at least one reservation
        for (auto const& [row, mask] : rowMasks) {
            bool isLeftFree = (mask & 0x3C) == 0;   // seats 2, 3, 4, 5
            bool isMiddleFree = (mask & 0xF0) == 0; // seats 4, 5, 6, 7
            bool isRightFree = (mask & 0x3C0) == 0; // seats 6, 7, 8, 9

            if (isLeftFree && isRightFree) {
                totalGroups += 2; // Can seat two non-overlapping groups (left and right)
            } else if (isLeftFree || isRightFree || isMiddleFree) {
                totalGroups += 1; // Can seat at least one group
            }
            // If none are free, 0 groups can be seated in this row
        }

        return totalGroups;
    }
};