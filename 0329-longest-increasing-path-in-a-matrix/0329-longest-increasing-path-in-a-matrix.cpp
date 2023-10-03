class Solution {
public:
    vector<vector<int>> dp;
    int DFS(vector<vector<int>>& mat,int i,int j,int last){
        int m=mat.size(), n=mat[0].size();
        if(i<0 || j<0 || i>=m ||j>=n || mat[i][j] <=last)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int a=DFS(mat,i-1,j,mat[i][j]);
        int b=DFS(mat,i,j-1,mat[i][j]);
        int c=DFS(mat,i+1,j,mat[i][j]);
        int d=DFS(mat,i,j+1,mat[i][j]);
        int res=max({a,b,c,d})+1;
        return dp[i][j]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        dp.resize(m,vector<int> (n,-1));
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(dp[i][j] == -1)
                    res=max(res,DFS(mat,i,j,-1));
        return res;
    }
};