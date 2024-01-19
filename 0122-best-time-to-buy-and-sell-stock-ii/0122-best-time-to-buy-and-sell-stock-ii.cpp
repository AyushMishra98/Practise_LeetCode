class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        
        vector<int> prev(2,0),curr(2,0);
        prev[0]=prev[1]=0;
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    int take=-p[idx]+prev[0];
                    int notTake=prev[1];
                    profit=max(take,notTake);
                }
                else{
                    int take=p[idx]+prev[1];
                    int notTake=prev[0];
                    profit=max(take,notTake);
                }
                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};