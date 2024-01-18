class Solution {
public:
    int minCount(int i,int j,string w1, string w2,vector<vector<int>>& dp){
        if(i == 0)
            return j;
        if(j == 0)
            return i;
        
        if(dp[i][j] == -1){
            if(w1[i-1] == w2[j-1])
                dp[i][j]=minCount(i-1,j-1,w1,w2,dp);
            else{
                int insert=minCount(i,j-1,w1,w2,dp);
                int replace=minCount(i-1,j-1,w1,w2,dp);
                int remove=minCount(i-1,j,w1,w2,dp);
                
                dp[i][j]=1+min(insert,min(replace,remove));
            }
        }
        return dp[i][j]; 
    }
    int minDistance(string w1, string w2) {
        int m=w1.length(),n=w2.length();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return minCount(m,n,w1,w2,dp);
    }
};