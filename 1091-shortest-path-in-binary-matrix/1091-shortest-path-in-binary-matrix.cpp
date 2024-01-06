class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        int x[8]={-1,-1,-1,0,1,1,1,0};
        int y[8]={-1,0,1,1,1,0,-1,-1};
        
        vector<vector<int>> vis(n,vector<int> (n,-1));
        
        vis[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
                auto r=q.front();
                q.pop();
                for(int j=0;j<8;j++){
                    int x1=r.first+x[j];
                    int y1=r.second+y[j];
                    if(x1>=0 && x1<n && y1>=0 && y1<n){
                        if(grid[x1][y1] == 1 || vis[x1][y1] != -1)
                            continue;
                        vis[x1][y1]=1+vis[r.first][r.second];
                        q.push({x1,y1});
                    }
                }
            }
        return vis[n-1][n-1];
    }
};