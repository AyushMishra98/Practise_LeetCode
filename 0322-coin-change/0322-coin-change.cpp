class Solution {
public:
    int countCoins(int idx,int amt,vector<int>& c,vector<vector<int>>& dp){
        if(idx == 0){
            if(amt%c[idx] == 0)
                return (amt/c[idx]);
            else
                return 1e9;
        }
        if(dp[idx][amt] == -1){
        
        int notTake=countCoins(idx-1,amt,c,dp);
        
        int take=INT_MAX;
        if(c[idx]<=amt)
            take=1+countCoins(idx,amt-c[idx],c,dp);
        
        dp[idx][amt]=min(take,notTake);
        }
        return dp[idx][amt];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        
        int temp=countCoins(coins.size()-1,amount,coins,dp);
            if(temp>=1e9)
                return -1;
        return temp;
    }
};