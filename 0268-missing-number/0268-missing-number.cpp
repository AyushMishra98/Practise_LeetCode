class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // int sum=(n*(n+1))/2;
        // for(auto x:nums)
        //     sum-=x;
        // return sum;
        int n=nums.size();
        int xor1=0,xor2=nums[0];
        for(int i=1;i<=n;i++)
            xor1=xor1^i;
        for(int i=1;i<n;i++)
            xor2=xor2^nums[i];
        return xor1^xor2;
    }
};