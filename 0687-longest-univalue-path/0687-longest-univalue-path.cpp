class Solution {
public:
    int maxLength = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int leftPath = dfs(root->left);
        int rightPath = dfs(root->right);

        int leftArrow = 0;
        int rightArrow = 0;

        if (root->left && root->left->val == root->val) {
            leftArrow = leftPath + 1;
        }

        if (root->right && root->right->val == root->val) {
            rightArrow = rightPath + 1;
        }

        maxLength = max(maxLength, leftArrow + rightArrow);

        return max(leftArrow, rightArrow);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxLength;
    }
};