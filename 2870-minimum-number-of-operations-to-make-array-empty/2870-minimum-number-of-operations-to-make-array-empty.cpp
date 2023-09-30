class Solution {
public:
    int calmin(int n,vector<int> &dp){
        if(n==0)
            return 0;
        if(n<0)
            return 1000000;
        if(dp[n] == -1){
            return dp[n]= 1+min(calmin(n-3,dp),calmin(n-2,dp));
        }
        return dp[n];
    }
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
        int maxi=INT_MIN;
        for(auto x:m)
            maxi=max(maxi,x.second);
        vector<int> dp(maxi+1,-1);
        int res=0;
        for(auto x:m){
            int temp=calmin(x.second,dp);
            if(temp >= 1000000)
                return -1;
            res+=temp;
        }
        return res;
    }
};