#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    // Helper function to find the first occurrence of the target
    int findFirst(const std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int idx = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) {
                idx = mid;
            }
        }
        return idx;
    }

    // Helper function to find the last occurrence of the target
    int findLast(const std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int idx = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (nums[mid] == target) {
                idx = mid;
            }
        }
        return idx;
    }
};