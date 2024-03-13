class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0)
                continue;
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[j] == 1)
                    count++;
                else{
                    maxi=max(maxi,count);
                    break;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};