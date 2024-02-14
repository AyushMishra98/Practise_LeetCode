class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int maxi=0;
        
        while(i<n){
            if(nums[i] == 0){
                i++;
                continue;
            }
            int j=i;
            int count=0;
            while(j<n && nums[j]==1){
                count++;
                j++;
            }
            maxi=max(maxi,count);
            i=j;
        }
        return maxi;
    }
};