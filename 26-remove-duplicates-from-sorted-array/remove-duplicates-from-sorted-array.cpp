#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0; // Points to the last unique element
        
        // Iterate through the array with the fast pointer j
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j]; // Update the position with the new unique element
            }
        }
        
        // Return the count of unique elements (index + 1)
        return i + 1;
    }
};