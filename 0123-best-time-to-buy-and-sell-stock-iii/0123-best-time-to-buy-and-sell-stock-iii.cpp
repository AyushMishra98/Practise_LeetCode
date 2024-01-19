class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int dp[n+1][2][3];
        memset(dp,0,sizeof dp);
        
        for(int idx=n-1;idx>=0;idx--){
            for(int flag=0;flag<2;flag++){
                for(int cap=2;cap>=0;cap--){
                    if(cap == 0)
                        continue;
            int profit=0;
            if(flag){ 
                int take=-p[idx]+dp[idx+1][0][cap];//buying
                int notTake=dp[idx+1][1][cap];
                profit=max(take,notTake);
                }
            else{   
                int take=p[idx]+dp[idx+1][1][cap-1];//selling 
                int notTake=dp[idx+1][0][cap];
                profit=max(take,notTake);
                }
                    dp[idx][flag][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};