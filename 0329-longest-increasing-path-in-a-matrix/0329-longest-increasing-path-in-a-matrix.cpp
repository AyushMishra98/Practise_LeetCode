class Solution {
public:
    int LIP(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        int m=mat.size(),n=mat[0].size();
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        if(dp[i][j] == -1){
            int maxi=1;
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                
                if(x<0 || x>=m || y<0 || y>=n)
                    continue;
                if(mat[i][j] < mat[x][y])
                    maxi=max(maxi,1+LIP(x,y,mat,dp));
            }
            dp[i][j]=maxi;
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int maxi=1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                maxi=max(maxi,LIP(i,j,mat,dp));
        return maxi;
    }
};