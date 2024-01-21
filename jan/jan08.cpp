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
    int dfs(TreeNode* r, int l, int h) {
            int s = (r->val >= l && r->val <= h) ? r->val : 0;
            
            if (r->left) s += dfs(r->left, l, h);
            if (r->right) s += dfs(r->right, l, h);

            return s;
        }

    int rangeSumBST(TreeNode* root, int low, int high) {
       return dfs(root, low, high);
    }
};
