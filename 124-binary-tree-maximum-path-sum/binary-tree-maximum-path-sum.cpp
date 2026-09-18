/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        auto dfs = [&](auto& self, TreeNode* node) -> int {
            if (!node) return 0;
            int left = max(0, self(self, node->left));
            int right = max(0, self(self, node->right));
            max_sum = max(max_sum, node->val + left + right);
            return node->val + max(left, right);
        };
        dfs(dfs, root);
        return max_sum;
    }
};