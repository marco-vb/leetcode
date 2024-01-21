class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> mem = nums;
        if (n > 2) mem[2] = nums[0] + nums[2];
         
        for (int i = 3; i < n; i++) {
            mem[i] = nums[i] + max(mem[i-2], mem[i-3]);
        }

        return *max_element(mem.begin(), mem.end());
    }
};
