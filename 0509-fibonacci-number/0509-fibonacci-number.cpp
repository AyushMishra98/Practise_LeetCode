class Solution {
public:
    int fi(int n,vector<int>& dp){
    if(n==0 || n==1)
        return n;
    
    if(dp[n] == -1)
        dp[n]=fi(n-1,dp)+fi(n-2,dp);

    return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fi(n,dp);
    }
};