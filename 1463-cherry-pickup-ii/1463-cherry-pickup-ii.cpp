class Solution {
public:
    int pickup(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int m=grid.size(),n=grid[0].size();
        
        if(i<0 || i>=m || j1<0 || j1>=n || j2<0 || j2>=n)
            return 0;
        
        if(dp[i][j1][j2] == -1){
            int sum=0;
        if(j1 == j2)
            sum=grid[i][j1];
        else
            sum=grid[i][j1]+grid[i][j2];
        
        int maxi=sum;
        int dx[]={-1,0,1};
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
               
            }
        }
        
        }
        return dp[i][j1][j2];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(n,0)));
        
        for(int i=m-1;i>=0;i--){
            for(int j1=n-1;j1>=0;j1--){
                for(int j2=0;j2<n;j2++){
                    
                    if(i == m-1){
                         if(j1 == j2)
                            dp[i][j1][j2]=grid[i][j1];
                        else
                            dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
                        continue;
                    }
                    
                    int sum;
                    if(j1 == j2)
                        sum=grid[i][j1];
                    else
                        sum=grid[i][j1]+grid[i][j2];
                        
                    int maxi=sum;
                    int dx[]={-1,0,1};
                    for(int j=0;j<3;j++)
                        for(int k=0;k<3;k++){
                            int x=j1+dx[j];
                            int y=j2+dx[k];
                            if(x<0 || x>=n || y<0 || y>=n)
                                continue;
                            maxi=max(maxi,sum+dp[i+1][x][y]);
                        }
                    dp[i][j1][j2]= maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
};