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
    const int maxn = 1e5 + 1;

    int depth(int r, vector<vector<int>>& g, vector<bool>& vis) {
        auto& al = g[r];

        if (al.empty()) return 0;

        vis[r] = 1;
        int mx = -1;

        for (int u : al) {
            if (!vis[u]) mx = max(mx, depth(u, g, vis));
        }

        return mx + 1;
    }

    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> g(maxn);
        vector<bool> vis(maxn, false);

        queue<TreeNode*> q;
        q.push(root);
        vis[root->val] = 1;

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            
            auto l = u->left, r = u->right;

            if (l && !vis[l->val]) {
                vis[l->val] = 1;
                g[u->val].push_back(l->val);
                g[l->val].push_back(u->val);
                q.push(l);
            }

            if (r && !vis[r->val]) {
                vis[r->val] = 1;
                g[u->val].push_back(r->val);
                g[r->val].push_back(u->val);
                q.push(r);
            }
        }

        for (int i = 0; i < maxn; i++) vis[i] = false;
        return depth(start, g, vis);
    }
};
