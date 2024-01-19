class Solution {
public:
    int maxProf(int idx,bool buy,vector<int>& p,vector<vector<int>>& dp){
        if(idx == p.size())
            return 0;
        
        if(dp[idx][buy] == -1){
        
        int profit=0;
            if(buy){
                int take=-p[idx]+maxProf(idx+1,0,p,dp);
                int notTake=maxProf(idx+1,1,p,dp);
                profit=max(take,notTake);
            }
            else{
                int take=p[idx]+maxProf(idx+1,1,p,dp);
                int notTake=maxProf(idx+1,0,p,dp);
                profit=max(take,notTake);
            }
            dp[idx][buy]=profit;
        }
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxProf(0,1,prices,dp);
    }
};