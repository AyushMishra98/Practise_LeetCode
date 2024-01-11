class Solution {
public:
    int countClimb(int n, vector<int>& dp){
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        if(dp[n] == -1)
            dp[n]=countClimb(n-1,dp)+countClimb(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return countClimb(n,dp);
    }
};