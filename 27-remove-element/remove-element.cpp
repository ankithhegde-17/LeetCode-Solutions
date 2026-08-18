#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0; // Points to the position where the next valid element should go
        
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        
        // i represents the count of elements not equal to val
        return i;
    }
};