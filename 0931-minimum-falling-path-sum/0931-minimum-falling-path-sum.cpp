class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m == 1)
            return matrix[0][0];
        
        int ans=INT_MAX;
        vector<vector<int>> dp(m,vector<int>(m,-1));

        for(int i=m-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){

                if(i == m-1){
                    dp[i][j]=matrix[i][j];
                    continue;
                }

                int mini=INT_MAX;
                if(j-1>=0)
                    mini=min(mini,dp[i+1][j-1]);

                mini=min(mini,dp[i+1][j]);

                if(j+1 <m)
                    mini=min(mini,dp[i+1][j+1]);

                dp[i][j]= matrix[i][j]+mini;

                if(i == 0)
                    ans=min(ans,dp[i][j]);
            }
        }
        return ans;
    }
};