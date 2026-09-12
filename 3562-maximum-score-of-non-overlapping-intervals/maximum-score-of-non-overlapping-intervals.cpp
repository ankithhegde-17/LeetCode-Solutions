#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct Result {
    long long weight;
    vector<int> indices;
};

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<tuple<int, int, int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(items.begin(), items.end());

        vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = get<0>(items[i]);
        }

        vector<vector<Result>> dp(n + 1, vector<Result>(5, {0, {}}));

        for (int i = n - 1; i >= 0; --i) {
            auto [l, r, w, orig_idx] = items[i];
            
            int next_idx = distance(starts.begin(), upper_bound(starts.begin(), starts.end(), r));

            for (int k = 1; k <= 4; ++k) {
                Result skip = dp[i + 1][k];
                
                Result pick;
                pick.weight = w + dp[next_idx][k - 1].weight;
                pick.indices = dp[next_idx][k - 1].indices;
                pick.indices.push_back(orig_idx);
                sort(pick.indices.begin(), pick.indices.end());

                if (skip.weight > pick.weight) {
                    dp[i][k] = skip;
                } else if (pick.weight > skip.weight) {
                    dp[i][k] = pick;
                } else {
                    dp[i][k] = (pick.indices < skip.indices) ? pick : skip;
                }
            }
        }

        return dp[0][4].indices;
    }
};