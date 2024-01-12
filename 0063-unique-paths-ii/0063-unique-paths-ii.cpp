class Solution {
public:
    int count(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0 ||grid[i][j]==1)
            return 0;
        if(dp[i][j] == -1){
            int up=count(grid,i-1,j,dp);
            int down=count(grid,i,j-1,dp);
        
            dp[i][j]=up+down;
        }
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return count(grid,m-1,n-1,dp);
    }
};