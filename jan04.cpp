class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> freq;
        
        for (int x : nums) freq[x]++;
        
        int ans = 0;
        
        for (auto& [k, v] : freq) {
            if (v == 1) return -1;
            
            ans += v/3;
            if (v % 3 != 0) ans += 1;
        }
        
        return ans;
    }
};
