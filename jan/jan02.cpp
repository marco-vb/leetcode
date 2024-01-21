class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans = {{nums.front()}};
        
        for (int i = 1; i < n; i++) {
            int ai = i;
            for (int j = ai; j < n && nums[j] == nums[j-1]; j++, ai++) {
                int midx = j - i + 1;
                if (midx < ans.size()) {
                    ans[midx].push_back(nums[j]);
                }
                else ans.push_back({nums[j]});
            }
            i = ai;
            if (i == n) break;
            ans.front().push_back(nums[i]);
        }
        
        return ans;
    }
};

