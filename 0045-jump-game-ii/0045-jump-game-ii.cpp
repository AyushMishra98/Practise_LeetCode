class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n-1;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j<n)
                    dp[i+j]=min(dp[i+j],1+dp[i]);
            }
        }
        return dp[n-1];
    }
};