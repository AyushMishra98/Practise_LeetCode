class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return 0;
        
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    curr[j]=1;
                
                if(grid[i][j] == 1)
                    continue;
                
                if(i>0)
                    curr[j]+=prev[j];
                if(j>0)
                    curr[j]+=curr[j-1];
            }
            prev=curr;
        }
        return prev[n-1];
    }
};