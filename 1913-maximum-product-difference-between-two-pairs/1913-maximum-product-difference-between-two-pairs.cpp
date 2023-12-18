class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int l1=0,l2=-1,s1=0,s2=-1;
        for(int i=1;i<nums.size();i++){
            //finding largest and second largest
            if(nums[i]>nums[l1]){
                l2=l1;
                l1=i;
            }
            else if(nums[i] == nums[l1] || l2 == -1 || nums[l2]<nums[i])
                l2=i;
                
            //finding minimum and second minimum
            if(nums[i] < nums[s1]){
                s2=s1;
                s1=i;
            }else if(nums[i] == nums[s1] || s2==-1 || nums[i]<nums[s2])
                s2=i;
        }
        return nums[l1]*nums[l2]-nums[s2]*nums[s1];
    }
};