class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;

        for (int i = 0; i < n; ++i) {
            if (i > reach) return false;          // unreachable — stuck here
            reach = max(reach, i + nums[i]);
            if (reach >= n - 1) return true;      // last index already covered
        }
        return true;
    }
};