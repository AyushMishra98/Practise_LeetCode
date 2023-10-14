class Solution {
public:
    vector<vector<int>> dp;
    int paint(vector<int>& cost, vector<int>& time,int idx,int n){
        if(n<=0)
            return 0;
        if(idx >= cost.size())
            return 1e9;
        if(dp[idx][n] == -1)
            dp[idx][n]= min(cost[idx]+paint(cost,time,idx+1,n-1-time[idx]),
                  paint(cost,time,idx+1,n));
        return  dp[idx][n];
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        dp.resize(n+1,vector<int> (n+1,-1));
        return paint(cost,time,0,n);
    }
};