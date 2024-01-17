class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        for(int amt=0;amt<=amount;amt++)
            if(amt%coins[0] == 0)
                prev[amt]=amt/coins[0];
            else
                prev[amt]=1e9;
        for(int idx=1;idx<n;idx++){
            for(int amt=0;amt<=amount;amt++){
            int notTake=prev[amt];
            
            int take=INT_MAX;
            if(coins[idx]<=amt)
                take=1+curr[amt-coins[idx]];
            
            curr[amt]=min(take,notTake);
            }
            prev=curr;
        }        
        return (prev[amount] >= 1e9)?-1:prev[amount];
    }
};