#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sort the candidates to handle duplicates and enable early stopping
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
            // Early termination: if the current element exceeds target, stop searching further
            if (candidates[i] > target) {
                break;
            }

            // Skip duplicate elements at the same recursion level to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Choose the candidate
            current.push_back(candidates[i]);
            
            // Recurse with `i + 1` because each number can only be used once
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            
            // Unchoose (backtrack) to explore alternative combinations
            current.pop_back();
        }
    }
};