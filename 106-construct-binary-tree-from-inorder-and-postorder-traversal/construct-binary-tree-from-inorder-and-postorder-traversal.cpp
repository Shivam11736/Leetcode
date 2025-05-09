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

    TreeNode* buildtreeHelperFunction(vector<int>& inorder, vector<int>& postorder, int size , int& postIndex , int inOrder_startInd ,int inOrder_endInd, unordered_map<int,int>& position_Inorder){
        //Base Case
        if(postIndex <0 || inOrder_startInd > inOrder_endInd) return NULL;

        //The Root Node is the right-Most element of postOrder array
        int root_value = postorder[postIndex];
        TreeNode* root = new TreeNode(root_value);
        postIndex--;

        //Find this root element in Inorder array
        int position = position_Inorder[root_value];

        //Construct Right SubTree first , because postorder traversal means L->R->N
        root->right = buildtreeHelperFunction(inorder , postorder , size , postIndex , position+1 , inOrder_endInd, position_Inorder);
        root->left = buildtreeHelperFunction(inorder , postorder , size , postIndex , inOrder_startInd , position-1, position_Inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() -1;
        int inOrder_startInd = 0;
        int inOrder_endInd = inorder.size() -1;
        int size = postorder.size(); 
        
        unordered_map<int, int> position_Inorder;
        for(int i=0; i<inorder.size(); i++){
            position_Inorder[inorder[i]] = i;
        }

        TreeNode* rootNode = buildtreeHelperFunction(inorder , postorder , size , postIndex , inOrder_startInd , inOrder_endInd, position_Inorder);

        return rootNode;
    }
};