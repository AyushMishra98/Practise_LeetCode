class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Optimal approach 1
        // int n=nums.size();
        // int sum=(n*(n+1))/2;
        // for(auto x:nums)
        //     sum-=x;
        // return sum;
        
        //Optimal approach 2
        int n=nums.size();
        int xor1=0,xor2=0;
        for(int i=0;i<n;i++){
            xor2=xor2^nums[i];
            xor1=xor1^i;
        }
        xor1=xor1^n;
        return xor1^xor2;
    }
};