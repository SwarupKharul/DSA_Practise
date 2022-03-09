vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res; // To store the result
    if (root == NULL)
        return res;
    stack<TreeNode *> s;      // To store the nodes
    TreeNode *cur = root;     // To store the current node
    while (cur || !s.empty()) // While there are nodes or the stack is not empty
    {
        while (cur) // While there are nodes
        {
            s.push(cur);     // Push the current node
            cur = cur->left; // Go to the left child
        }
        cur = s.top();           // Get the top node
        s.pop();                 // Pop the top node
        res.push_back(cur->val); // Add the value of the top node to the result
        cur = cur->right;        // Go to the right child
    }
    return res;
}