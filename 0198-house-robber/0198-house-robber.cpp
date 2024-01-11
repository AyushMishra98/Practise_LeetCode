class Solution {
public:
    int rob(vector<int>& nums) {
    int n=nums.size();
    if(n == 1)
        return nums[0];

    int prev2=nums[0];
    int prev=max(nums[0],nums[1]);

    for(int i=2;i<n;i++){
        int l=max(nums[i],prev);
        int r=nums[i]+prev2;
        prev2=prev;
        prev=max(l,r);
    }
    return prev;
    }
};