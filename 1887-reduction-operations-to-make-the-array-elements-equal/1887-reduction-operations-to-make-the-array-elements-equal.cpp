class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int mini=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1])
                mini++;
            count+=mini;
        }
        return count;
    }
};