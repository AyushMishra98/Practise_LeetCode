class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm
        int n=nums.size();
        int res=0,count=0;
        for(int i=0;i<n;i++){
            if(nums[i] == nums[res])
                count++;
            else
                count--;
            if(count == 0){
                res=i;
                count=1;
            }
        }
        count=0;
        for(int i=0;i<n;i++)
            if(nums[i] == nums[res])
                count++;
        if(count>n/2)
            return nums[res];
        return -1;
    }
};