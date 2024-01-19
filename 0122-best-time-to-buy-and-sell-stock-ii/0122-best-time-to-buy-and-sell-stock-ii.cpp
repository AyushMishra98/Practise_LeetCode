class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        
        int aheadBuy,aheadNotBuy,currBuy,currNotBuy;
        aheadBuy=aheadNotBuy=0;
        
        for(int idx=n-1;idx>=0;idx--){
            currBuy=max(-p[idx]+aheadNotBuy,aheadBuy);
            
            currNotBuy=max(p[idx]+aheadBuy,aheadNotBuy);
            
            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        return aheadBuy;
    }
};