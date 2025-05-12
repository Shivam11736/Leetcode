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
    void helper(TreeNode* root,int sum,int targetsum,vector<int> ans,vector<vector<int>>& finalans){
        if(root==NULL) return;
        sum+=root->val;
        ans.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetsum){
                finalans.push_back(ans);
                return;
            }
        }
        helper(root->left,sum,targetsum,ans,finalans);
        helper(root->right,sum,targetsum,ans,finalans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> finalans;
        vector<int> ans;
        int sum = 0;
        helper(root,sum,targetSum,ans,finalans);
        return finalans;
    }
};