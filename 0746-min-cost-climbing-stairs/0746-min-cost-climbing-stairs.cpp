class Solution {
public:
    int calCost(vector<int>& cost,vector<int>& memo,int i){
        if(i>=cost.size())
            return 0;
        if(memo[i]==-1)
            return memo[i]=min(calCost(cost,memo,i+1)+cost[i],calCost(cost,memo,i+2)+cost[i]);
      return memo[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(),-1);
        return min(calCost(cost,memo,0),calCost(cost,memo,1));
    }
};