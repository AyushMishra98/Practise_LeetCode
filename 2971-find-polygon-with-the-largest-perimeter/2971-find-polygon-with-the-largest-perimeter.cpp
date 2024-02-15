class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long res=0,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum>nums[i])
                res=sum+nums[i];
            sum+=nums[i];
        }
        return (res==0)?-1:res;
    }
};