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
    vector<int> leaves(TreeNode* r) {
        if (!r) return {};
        if (!r->left && !r->right) return {r->val};

        auto la = leaves(r->left), ra = leaves(r->right);

        for (int x : ra) la.push_back(x);

        return la;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return leaves(root1) == leaves(root2);
    }
};
