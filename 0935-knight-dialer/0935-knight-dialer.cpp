class Solution {
public:
    int mod=1e9+7;
    unordered_map<int,vector<int>> m;
    vector<vector<int>> dp;
    int rec(int n,int temp){
        if(n == 0)
            return 1;
        
        if(dp[n][temp]!=-1)
            return dp[n][temp];
        
        int ans=0;
        for(auto x:m[temp])
            ans=(ans+rec(n-1,x))%mod;
        
        return dp[n][temp]=ans;
    }
    int knightDialer(int n) {
        dp.resize(n+1,vector<int> (10,-1));
        m[0]={4,6};
        m[1]={6,8};
        m[2]={7,9};
        m[3]={4,8};
        m[4]={0,3,9};
        m[6]={0,1,7};
        m[7]={2,6};
        m[8]={1,3};
        m[9]={2,4};
        int ans=0;
        for(int i=0;i<10;i++)
            ans=(ans+rec(n-1,i))%mod;
        return ans;
    }
};