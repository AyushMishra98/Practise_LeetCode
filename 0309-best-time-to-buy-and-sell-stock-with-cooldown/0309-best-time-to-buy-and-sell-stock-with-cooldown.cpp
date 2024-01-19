class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<int> ahead(2,0),after(2,0),curr(2,0);
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    int take=-p[idx]+after[0];
                    int notTake=after[1];
                    profit=max(take,notTake);
                }else{
                    int take=p[idx]+ahead[1];
                    int notTake=after[0];
                    profit=max(take,notTake);
                }
                curr[buy]=profit;
            }
            ahead=after;
            after=curr;
        }
        return after[1];
    }
};