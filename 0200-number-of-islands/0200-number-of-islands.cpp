class Solution {
public:
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    void BFS(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size())
            return;
        if(j<0 || j>=grid[0].size())
            return;
        if(grid[i][j] == '0')
            return;
        grid[i][j]='0';
        for(int r=0;r<4;r++)
            BFS(grid,i+x[r],j+y[r]);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j] == '1'){
                    cout<<grid[i][j]<<" ";
                    count++;
                    BFS(grid,i,j);
                }
        return count;
    }
};