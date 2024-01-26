class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            int len=0;
            int maxSum=0;
            int sum=0;
            int maxi=0;
       
            for(int j=i;j<min(i+k,n);j++){
                len++;
                maxi=max(maxi,arr[j]);
                sum=len*maxi+dp[j+1];
                maxSum=max(sum,maxSum);
            }
            dp[i]=maxSum;
        }
        return dp[0];
    }
};