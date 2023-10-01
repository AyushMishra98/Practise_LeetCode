class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target=0;
        int n=nums.size();
        for(auto num:nums)
            target+=num;
        target-=x;
        int maxLen=INT_MIN,curr=0,left=0,right=0;
        while(right<n){
            curr+=nums[right];
            while(left<=right && curr>target){
                curr=curr-nums[left];
                left++;
            }
            if(curr == target)
                maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen!=INT_MIN ?n-maxLen:-1;
    }
};