class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int lSum=0,rSum=0;
      for(auto x:nums)
        rSum+=x;
      for(int i=0;i<nums.size();i++){
        rSum-=nums[i];
        if(lSum == rSum)
          return i;
        lSum+=nums[i];
      }
      return -1;
    }
};