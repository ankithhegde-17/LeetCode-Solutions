#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // If such an element is found
        if (i >= 0) {
            // Step 2: Find the smallest element greater than nums[i] to its right
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap nums[i] and nums[j]
            std::swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse the sub-array to the right of i to get the lowest lexicographical order
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};