#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // Calculate the current water container area
            int current_width = right - left;
            int current_height = std::min(height[left], height[right]);
            int current_area = current_width * current_height;
            
            // Update the maximum water found
            max_water = std::max(max_water, current_area);
            
            // Move the pointer of the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};