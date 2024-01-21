class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> f;
        for (int x : arr) f[x]++;

        vector<int> v;
        for (auto& [k, vl] : f) v.push_back(vl);

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] == v[i+1]) return false;
        }

        return true;
    }
};
