class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 2)
                    q.push({{i,j},0});
        
        int x[4]={-1,0,1,0};
        int y[4]={0,1,0,-1};
        
        int res=0;
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                
                auto X=q.front();
                q.pop();
                
                int i=X.first.first;
                int j=X.first.second;
                int time=X.second;
                
                res=max(res,time);
                
                //checking whether it has affected anyone or not
                bool flag=false;
                int dx,dy;
                
                for(int r=0;r<4;r++){
                    dx=i+x[r] ,dy=j+y[r];
                    if(((dx>=0 && dx<m) && (dy>=0 && dy<n)) && grid[dx][dy] == 1){
                        q.push({{dx,dy},time+1});
                        grid[dx][dy]=2;
                        flag=true;
                    }
                }
            }
        }
        //checking whether there is any left fresh orange
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 1)
                    return -1;
        return res;
    }
};