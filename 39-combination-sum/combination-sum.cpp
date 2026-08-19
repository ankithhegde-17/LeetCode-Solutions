#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sort candidates to enable early termination during backtracking
        std::sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& candidates, int target, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if target reaches 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Since candidates are sorted, if the current element exceeds the target, 
            // all subsequent elements will also exceed it, so we can break early.
            if (candidates[i] > target) {
                break;
            }

            // Choose the candidate
            current.push_back(candidates[i]);
            
            // Recurse with 'i' (instead of 'i + 1') because the same number can be used multiple times
            backtrack(candidates, target - candidates[i], i, current, result);
            
            // Unchoose (backtrack) to explore other combinations
            current.pop_back();
        }
    }
};