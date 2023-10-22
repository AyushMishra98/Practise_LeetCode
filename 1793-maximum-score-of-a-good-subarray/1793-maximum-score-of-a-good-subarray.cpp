class Solution {
public:
    //Similar to container with most water
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int l=k;
        int r=k;
        int ans=nums[k];
        int currMin = nums[k];
        
        while (l>0 || r<n-1){
            if((l > 0 ? nums[l-1]:0) < (r<n-1?nums[r + 1]:0)){
                r++;
                currMin = min(currMin, nums[r]);
            }else{
                l--;
                currMin = min(currMin, nums[l]);
            }
            ans = max(ans,currMin*(r-l+1));
        }
        return ans;
    }
};