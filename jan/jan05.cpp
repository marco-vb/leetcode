class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), k = 0;
        vector<int> curr;
        
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(curr.begin(), curr.end(), nums[i]) - curr.begin();
            
            if (idx == k) curr.push_back(nums[i]), k++;
            else curr[idx] = nums[i];
        }
        
        return k;
    }
};

