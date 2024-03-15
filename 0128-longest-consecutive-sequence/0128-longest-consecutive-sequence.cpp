class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(),nums.end());
        int res=1;
        
        int prev=0;
        int count=1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[prev])
                continue;
            else if(nums[i] == (nums[prev]+1)){
                count++;
                res=max(res,count);
                prev=i;
            }
            else{
                count=1;
                prev=i;
            }
            
        }
        return res;
    }
};