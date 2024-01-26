class Solution {
public:
    int countPaths(int i,int j,int maxMove,int m, int n,vector<vector<vector<int>>>& dp){
        if(i<0 || i>=m || j<0 ||j>=n)
            return 1;
        
        if(maxMove == 0)
            return 0;
        
        int mod =1e9+7;
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        if(dp[i][j][maxMove] == -1){
            int move=0;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                move=(move+countPaths(x,y,maxMove-1,m,n,dp))%mod;
            }
            dp[i][j][maxMove]=move;
        }
        return dp[i][j][maxMove];
    }
    int findPaths(int m, int n, int maxMove, int sR, int sC) {      
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (maxMove+1,-1)));
        return countPaths(sR,sC,maxMove,m,n,dp);
    }
};