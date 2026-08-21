#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};