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

    void solve(TreeNode* &root, TreeNode* &prev, TreeNode* &firstViolation, TreeNode* &secondViolation) { 
        // bc
        if (!root) return;

        // LNR
        // L
        solve(root->left, prev, firstViolation, secondViolation);

        // N
        // store and compute
        // check wether property violated
        if (prev && prev->val > root->val) {
            // case 01 : adjacent node violation
            // case 02 : not adjacent node violation

            // locally optimal soln
            // if first violation
            if (!firstViolation) firstViolation = prev;
            // if second violation then it automatically store in SV
            secondViolation = root;
        }
        // update prev
        prev = root;
        
        // R
        solve(root->right, prev, firstViolation, secondViolation);
    }

    void recoverTree(TreeNode* root) {
        // 01 approach - inorder vector + sort + cmp + inorder traverse and set values

        // 02 approach - inorder traverse with prev pointer and find violations (cond)
        TreeNode* prev = nullptr;
        TreeNode* firstViolation = nullptr;
        TreeNode* secondViolation = nullptr;
        solve(root, prev, firstViolation, secondViolation);

        // swap val
        if (firstViolation && secondViolation) swap(firstViolation->val, secondViolation->val);
    }
};