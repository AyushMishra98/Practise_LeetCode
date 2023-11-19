class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int idx=0;
        int mini=0;
        while(idx<nums.size()){
            int i=idx;
            while(i<nums.size()-1 && nums[i]==nums[i+1])
                i++;
            count+=(i-idx+1)*mini;
            mini++;
            idx=i;
            idx++;
        }
        return count;
    }
};