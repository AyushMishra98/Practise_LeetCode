class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
        return 0;
        int res=INT_MIN,minval=prices[0];
        for(int j=1;j<prices.size();j++){
            res=max(res,prices[j]-minval);
            minval=min(minval,prices[j]);
        }
        return (res<0)?0:res;
    }
};