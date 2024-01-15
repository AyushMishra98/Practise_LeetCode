class Solution {
public:
    //refer to codestudio for this
    bool subsetSumToK(int n, int k, vector<int> &arr) {
   
    vector<bool> prev(2*k+1,0),curr(2*k+1,0);
    prev[0]=curr[0]=1;
    
    prev[arr[0]]=true;

    for(int i=1;i<n;i++){
        for (int t = 1; t <= k; t++) {
          curr[t] = prev[t];
          if (arr[i] <= t)
            curr[t] = curr[t] || prev[t - arr[i]];
        }
        prev=curr;
    }
    return prev[k];
    // Write your code here.
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
            sum+=x;
        if(sum%2 == 1)
            return false;
        return subsetSumToK(nums.size(),sum/2,nums);
    }
};