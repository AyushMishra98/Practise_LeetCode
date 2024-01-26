class Solution {
public:
    bool isPalindrome(int i,int j,string& str){
        while(i<j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minimumCuts(int i,int n,string& s,vector<int>& dp){
        if(i == n)
            return 0;
        
        if(dp[i] == -1){
        
            int mini=INT_MAX;
        
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cost=1+minimumCuts(j+1,n,s,dp);
                    mini=min(mini,cost);
                }
            }
        dp[i]= mini;
        }
        return dp[i];
    }
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return minimumCuts(0,n,s,dp)-1;
    }
};