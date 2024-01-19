class Solution {
public:
    int maxPro(int idx,bool buy,int fee,vector<int>& p){
        if(idx == p.size())
            return 0;
        
        int profit=0;
        if(buy){
            int take=-p[idx]+maxPro(idx+1,0,fee,p);
            int notTake=maxPro(idx+1,1,fee,p);
            profit=max(take,notTake);
        }
        else{
            int take=p[idx]-fee+maxPro(idx+1,1,fee,p);
            int notTake=maxPro(idx+1,0,fee,p);
            profit=max(take,notTake);
        }
        return profit;
    }
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        
        for(int idx=n-1;idx>=0;idx--){
            
            dp[idx][1]=max(-p[idx]+dp[idx+1][0],dp[idx+1][1]);
            dp[idx][0]=max(p[idx]-fee+dp[idx+1][1],dp[idx+1][0]);
            
        }
        return dp[0][1];
    }
};