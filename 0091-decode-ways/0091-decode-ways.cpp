class Solution {
public:
    vector<int> dp;
    bool check(string s,int idx){
        if(idx < s.length()-1){
            int val=(s[idx]-'0')*10+(s[idx+1]-'0');
            if(val <= 26)
                return true;
        }
        return false;
    }
    int countPatterns(string s,int idx){
        if(idx >= s.length())
            return 1;
        if(s[idx] == '0')
            return 0;
        if(dp[idx] == -1){
            dp[idx]=0;
            dp[idx]+=countPatterns(s,idx+1);
            if(check(s,idx))
            dp[idx]+=countPatterns(s,idx+2);
        }
        return dp[idx];
    }
    int numDecodings(string s) {
        dp.resize(s.length(),-1);
        return countPatterns(s,0);
    }
};