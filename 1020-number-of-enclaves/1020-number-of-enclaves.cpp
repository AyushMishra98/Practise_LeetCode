class Solution {
public:
    //T.C=A.S=O(m*n)
    //multi source BFS
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size() ,n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if((i==0||j==0||i==m-1||j==n-1) && (grid[i][j]==1)){
                    vis[i][j]=true;
                    q.push({i,j});
                }
        
        int x[4]={-1,0,1,0};
        int y[4]={0,1,0,-1};
        
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                
                auto temp=q.front();
                q.pop();
                
                int i=temp.first;
                int j=temp.second;
                int dx,dy;
                for(int r=0;r<4;r++){
                    dx=i+x[r];
                    dy=j+y[r];
                if((dx>=0 && dx<m)&&(dy>=0 && dy<n)&& vis[dx][dy] == false && grid[dx][dy] == 1){
                        vis[dx][dy]=true;
                        q.push({dx,dy});
                    }
                }
            }
        }  
        int count=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 1 && vis[i][j]==false)
                    count++;
        return count;
    }
};