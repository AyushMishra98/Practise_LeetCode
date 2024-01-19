class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<int> ahead(2,0),after(2,0),curr(2,0);
        
        for(int idx=n-1;idx>=0;idx--){
            
            curr[1]=max(-p[idx]+after[0],after[1]);
            curr[0]=max(p[idx]+ahead[1],after[0]);
            
            ahead=after;
            after=curr;
        }
        return after[1];
    }
};