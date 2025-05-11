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

    void solve(TreeNode* &root, int &i, int &mini) {
        // bc
        if (!root) return;

        // check on leaf node
        if (!root->left && !root->right) {
            // include curr node
            i++;
            mini = min(mini, i);
            // bt
            i--;
            return;
        }

        // count node
        i++;
        solve(root->left, i, mini);
        solve(root->right, i, mini);
        // bt
        i--;
    }

    int minDepth(TreeNode* root) {
        // mempty
        if (!root) return 0;

        int i = 0;
        int mini = INT_MAX;

        solve(root, i, mini);

        return mini;
    }
};