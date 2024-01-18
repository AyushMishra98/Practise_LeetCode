class Solution {
public:
    int count(int i,int j,string s, string t,vector<vector<int>>& dp){
        if(j == 0)
            return 1;
        if(i == 0)
            return 0;
        
        if(dp[i][j] == -1){
            if(s[i-1] == t[j-1])
                dp[i][j]=count(i-1,j-1,s,t,dp)+count(i-1,j,s,t,dp);
        else
                dp[i][j]=count(i-1,j,s,t,dp);
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return count(n,m,s,t,dp);
    }
};