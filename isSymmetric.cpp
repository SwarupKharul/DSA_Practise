bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root);
}

bool isMirror(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return 1;

    if (p && q && p->val == q->val)
        return (isMirror(p->left, q->right) && isMirror(p->right, q->left)); // important: left and right are swapped

    return 0;
}