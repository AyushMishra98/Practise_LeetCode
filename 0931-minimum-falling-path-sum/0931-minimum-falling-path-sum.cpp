class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m == 1)
            return matrix[0][0];
        
        int ans=INT_MAX;
        
        vector<int> prev(m);
        for(int i=m-1;i>=0;i--){
            vector<int> temp(m);
            for(int j=m-1;j>=0;j--){

                if(i == m-1){
                    temp[j]=matrix[i][j];
                    continue;
                }

                int mini=INT_MAX;
                if(j-1>=0)
                    mini=min(mini,prev[j-1]);

                mini=min(mini,prev[j]);

                if(j+1 <m)
                    mini=min(mini,prev[j+1]);

                temp[j]= matrix[i][j]+mini;

                if(i == 0)
                    ans=min(ans,temp[j]);
            }
            prev=temp;
        }
        return ans;
    }
};