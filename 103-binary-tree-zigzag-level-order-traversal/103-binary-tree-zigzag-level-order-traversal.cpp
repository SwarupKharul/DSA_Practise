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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root==NULL) 
            return ans;
        
        queue<TreeNode*> myqueue;
        
        myqueue.push(root);
        int flag=true;
        
        while(!myqueue.empty()){
            int length = myqueue.size();
            vector<int> subans(length);
            for(int i=0; i<length; i++){
                TreeNode* temp = myqueue.front();
                myqueue.pop();
                int ind = flag ? i: (length-i-1);
                subans[ind] = temp->val;
                if(temp->left) myqueue.push(temp->left);
                if (temp->right) myqueue.push(temp->right);
            }
            ans.push_back(subans);
            flag = !flag;
        }
        return ans;
    }
};