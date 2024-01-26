class Solution {
public:
    int findPaths(int m, int n, int maxMove, int sR, int sC) {     
        vector<vector<int>> prev(m+2,vector<int> (n+2,0)),after(m+2,vector<int> (n+2,0));
        
        int mod =1e9+7;
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
            for(int i=0;i<m+2;i++){
                for(int j=0;j<n+2;j++){
                    if(i==0 || j==0|| i==m+1 || j==n+1){
                        prev[i][j]=1;
                        after[i][j]=1;
                    }
                }
            }
        for(int mv=1;mv<=maxMove;mv++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    int move=0;
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        move=(move+prev[x][y])%mod;
                    }
                    after[i][j]=move;
                }
            }
            prev=after;
        }
        return  prev[sR+1][sC+1];
    }
};