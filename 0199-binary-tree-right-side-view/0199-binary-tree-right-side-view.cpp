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
    vector<int>solve(TreeNode* root, vector<int>ans){
        queue<TreeNode*>q;
        q.push(root);

        while ( ! q.empty() ){ 

            vector<int>level; 
            int levelSize = q.size(); 

            for ( int i = 0 ; i < levelSize ; ++i ){ 
                TreeNode* node = q.front(); 
                q.pop(); 

                level.push_back(node->val); 

                if ( node->left )q.push(node->left);
                if ( node->right )q.push(node->right); 
            }

            ans.push_back(level[level.size()-1]);
        }

        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;

        if (!root ) return ans;
        
        return solve(root,ans);
    }
};