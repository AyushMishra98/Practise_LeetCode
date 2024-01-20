class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int idx=0;idx<n;idx++){
            for(int prev_idx=0;prev_idx<idx;prev_idx++){
                if(nums[prev_idx] < nums[idx])
                    dp[idx]=max(dp[idx],1+dp[prev_idx]);
            }
            maxi=max(maxi,dp[idx]);
        }
        return maxi;
    }
};