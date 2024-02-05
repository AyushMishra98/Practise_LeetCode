class Solution {
public:
    bool match(int i,int j,string s,string p,vector<vector<int>>& dp){
        if(i == s.size() && j >= p.size())
            return true;
        
        if(j >= p.size())
            return false;
        if(dp[i][j] == -1){
             
            bool flag=i<s.size() &&(s[i] == p[j] || p[j] == '.');
            if(j+1<p.size() && p[j+1] == '*')
                flag=match(i,j+2,s,p,dp)||(flag && match(i+1,j,s,p,dp));
            else if(flag)
                flag= match(i+1,j+1,s,p,dp);
        dp[i][j]=flag;
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return match(0,0,s,p,dp);
    }
};