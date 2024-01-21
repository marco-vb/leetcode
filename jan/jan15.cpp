class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        using ii = pair<int, int>;

        map<int, ii> mp;

        for (auto& m : matches) {
            mp[m[0]].first++;
            mp[m[1]].second++;
        }

        vector<vector<int>> ans(2);

        for (auto& [k, v] : mp) {
            int l = v.second;
            if (l == 0) ans.front().push_back(k);
            if (l == 1) ans.back().push_back(k);
        }

        return ans;
    }
};
