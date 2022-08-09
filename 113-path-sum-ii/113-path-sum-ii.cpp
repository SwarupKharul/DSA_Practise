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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        helper(root, curr, targetSum);
        return res;    
    }
    
    void helper(TreeNode* root, vector<int> &curr, int targetSum){
        if(!root) return;
        int newsum  = targetSum - root->val;
        curr.push_back(root->val);
        if(!root->right && !root->left && newsum==0){
            res.push_back(curr);
        }
        if(root->left){ 
            helper(root->left, curr, newsum);
            curr.pop_back();
        }        
        if(root->right) {
            helper(root->right, curr, newsum);
            curr.pop_back();
        }
    }
};