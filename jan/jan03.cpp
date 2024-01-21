class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<string> san;
        
        for (auto& s : bank) {
            if (count(s.begin(), s.end(), '1') == 0) continue;
            san.push_back(s);
        }
        
        int n = san.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            auto& s = san[i];
            auto& b = san[i-1];
            int t = count(s.begin(), s.end(), '1');
            int bt = count(b.begin(), b.end(), '1');
            ans += bt * t;
        }
        
        return ans;
    }
};

