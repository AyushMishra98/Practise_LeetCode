class Solution {
public:
    int Combinations(vector<int>& nums,vector<int> &dp,int t){
        if(t == 0)
            return 1;
        if(t < 0)
            return 0;
        if(dp[t] == -1){
            dp[t]=0;
            for(int i=0;i<nums.size();i++)
                dp[t]+=Combinations(nums,dp,t-nums[i]);
        }
        return dp[t];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1001,-1);
        return Combinations(nums,dp,target);
    }
};