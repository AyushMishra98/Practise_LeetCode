class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> after(2,vector<int> (3,0)),curr(2,vector<int> (3,0));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int flag=0;flag<2;flag++){
                for(int cap=1;cap<3;cap++){
                    int profit=0;
                    if(flag){ 
                        int take=-p[idx]+after[0][cap];//buying
                        int notTake=after[1][cap];
                        profit=max(take,notTake);
                        }
                    else{   
                        int take=p[idx]+after[1][cap-1];//selling 
                        int notTake=after[0][cap];
                        profit=max(take,notTake);
                        }
                    curr[flag][cap]=profit;
                }
            }
            after=curr;
        }
        return after[1][2];
    }
};