class Solution {
public:
    int LIS(int idx,int prev_idx,vector<int>& nums,vector<vector<int>>&dp){
        if(idx == nums.size())
            return 0;
        
        if(dp[idx][prev_idx+1] == -1){
            
            int notTake=LIS(idx+1,prev_idx,nums,dp);
            int take=0;
            if(prev_idx == -1 || nums[idx]>nums[prev_idx])
                take=1+LIS(idx+1,idx,nums,dp);
            
            dp[idx][prev_idx+1]=max(take,notTake);
        }
        return dp[idx][prev_idx+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return LIS(0,-1,nums,dp);
    }
};