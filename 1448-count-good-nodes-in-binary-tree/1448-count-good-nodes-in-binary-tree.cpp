class Solution {
public:
    int findCount(TreeNode* root, int count, int maxTill) {
        if (!root)
            return count;

        if (root->val >= maxTill) {
            count++;
            maxTill = root->val;
        }

        count = findCount(root->left, count, maxTill);
        count = findCount(root->right, count, maxTill);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return findCount(root, 0, INT_MIN);
    }
};