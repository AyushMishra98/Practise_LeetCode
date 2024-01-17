class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        for(int amt=0;amt<=amount;amt++)
            if(amt%coins[0] == 0)
                prev[amt]=1;
        
        for(int idx=1;idx<n;idx++){
            for(int amt=0;amt<=amount;amt++){
                
                int notTake=prev[amt];
                int take=0;
                if(coins[idx]<=amt)
                    take=curr[amt-coins[idx]];
        
                curr[amt]=take+notTake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};