#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to use the two-pointer approach
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If we find an exact match, return immediately
                if (currentSum == target) {
                    return target;
                }
                
                // Update closestSum if the current sum is closer to target
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Adjust pointers based on the sum comparison
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};