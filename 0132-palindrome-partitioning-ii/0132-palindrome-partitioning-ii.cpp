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
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        
        for(int i=n-1;i>=0;i--){
            
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cost;
                    if(j == n-1)
                        cost=1;
                    else
                        cost=1+dp[j+1];
                    mini=min(mini,cost);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};