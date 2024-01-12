class Solution {
public:
    //Tabulation 
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        vector<int> prev(n);
        for(int i=0;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[0]=grid[0][0];
                    continue;
                }
                int mini=INT_MAX;
                if(i>0)
                    mini=min(mini,prev[j]);
                if(j>0)
                    mini=min(mini,temp[j-1]);
                mini=mini+grid[i][j];
                temp[j]=mini;
            }
            prev=temp;
        }
        return prev[n-1];
    }
};