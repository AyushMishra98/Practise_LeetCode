class Solution {
public:
    int numSquares(int n) {
    if(n<=3)
      return n;
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = i;
        for (int x=sqrt(i);x>=1;x--)
            dp[i] = min(dp[i], 1 +dp[i - x*x]);
    }
    return dp[n];
    }
};