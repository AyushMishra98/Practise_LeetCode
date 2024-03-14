class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices[0];
        for(auto x:prices){
            int cost=x-mini;
            profit=max(profit,cost);
            mini=min(mini,x);
        }
        return profit;
    }
};