class Solution {
public:

    bool mirror(TreeNode* a, TreeNode* b) {

        if (!a && !b)
            return true;

        if (!a || !b)
            return false;

        if (a->val != b->val)
            return false;

        return mirror(a->left, b->right) &&
               mirror(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (!root)
            return true;

        return mirror(root->left, root->right);
    }
};