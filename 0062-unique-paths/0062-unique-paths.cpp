class Solution {
public:
    int countPaths(int m, int n,vector<vector<int>>& dp){
        if(m == 0 && n == 0)
            return 1;
        if(m<0 || n<0)
            return 0;
        
        if(dp[m][n] == -1){
            
        int l=countPaths(m-1,n,dp);
        int r=countPaths(m,n-1,dp);
        dp[m][n]=l+r;
        }
        
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return countPaths(m-1,n-1,dp);
    }
};