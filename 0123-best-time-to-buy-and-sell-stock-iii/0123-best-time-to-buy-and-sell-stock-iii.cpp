class Solution {
public:
    int maxProf(int idx,bool flag,int cap,vector<int>& p){
        if(cap == 0)
            return 0;
        if(idx == p.size())
            return 0;
        int profit=0;
        if(flag){ 
            int take=-p[idx]+maxProf(idx+1,0,cap,p);//buying
            int notTake=maxProf(idx+1,1,cap,p);
            profit=max(take,notTake);
        }
        else{   
            int take=p[idx]+maxProf(idx+1,1,cap-1,p);//selling 
            int notTake=maxProf(idx+1,0,cap,p);
            profit=max(take,notTake);
        }
        return profit;
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int dp[n+1][2][3];
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                dp[n][i][j]=0;
        
        for(int idx=n-1;idx>=0;idx--){
            for(int flag=0;flag<2;flag++){
                for(int cap=2;cap>=0;cap--){
                    if(cap == 0){
                        dp[idx][flag][0]=0;
                        continue;
                    }
                    
            int profit=0;
            if(flag){ 
                int take=-p[idx]+dp[idx+1][0][cap];//buying
                int notTake=dp[idx+1][1][cap];
                profit=max(take,notTake);
                }
            else{   
                int take=p[idx]+dp[idx+1][1][cap-1];//selling 
                int notTake=dp[idx+1][0][cap];
                profit=max(take,notTake);
                }
                    dp[idx][flag][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};