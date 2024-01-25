class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int c=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        
        for(int i=c;i>=1;i--){
            for(int j=i;j<=c;j++){
    
                int maxi=0;
                for(int k=i;k<=j;k++){
                int cost=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                maxi=max(maxi,cost);
                }
                
                dp[i][j]=maxi;
            }
        }
        return dp[1][c];
    }
};