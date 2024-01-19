class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                if(idx == n-1){
                    if(buy)
                        dp[idx][buy]=0;
                    else
                        dp[idx][buy]=p[n-1];
                    continue;
                }
                int profit=0;
                if(buy){
                    int take=-p[idx]+dp[idx+1][0];
                    int notTake=dp[idx+1][1];
                    profit=max(take,notTake);
                }
                else{
                    int take=p[idx]+dp[idx+1][1];
                    int notTake=dp[idx+1][0];
                    profit=max(take,notTake);
                }
                dp[idx][buy]=profit;
            }
        }
        return dp[0][1];
    }
};