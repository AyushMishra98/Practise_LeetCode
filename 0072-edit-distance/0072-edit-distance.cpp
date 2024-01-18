class Solution {
public:
    int minCount(int i,int j,string w1, string w2,vector<vector<int>>& dp){
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        
        if(dp[i][j] == -1){
            if(w1[i] == w2[j])
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
        int l1=w1.length(),l2=w2.length();
        vector<vector<int>> dp(l1,vector<int> (l2,-1));
        return minCount(l1-1,l2-1,w1,w2,dp);
    }
};