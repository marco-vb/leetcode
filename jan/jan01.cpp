class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        int n = g.size(), m = s.size();
        while (i < n && j < m) {
            if (g[i] <= s[j]) i++, j++;
            else j++;
        }
        
        return i;
    }
};

