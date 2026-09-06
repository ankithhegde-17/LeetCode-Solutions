class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        function<void(int, vector<int>&)> f = [&](int i, vector<int>& cur) {
            ans.push_back(cur);
            for (int j = i; j < nums.size(); j++) {
                if (j > i && nums[j] == nums[j - 1]) continue;
                cur.push_back(nums[j]);
                f(j + 1, cur);
                cur.pop_back();
            }
        };

        vector<int> cur;
        f(0, cur);
        return ans;
    }
};