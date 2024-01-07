class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        
        int count=0;
        
        while(i<n-1){
            int temp=0;
            while(i<n-1 && nums[i]-nums[i-1] == nums[i+1]-nums[i]){
                temp++;
                count+=temp;
                i++;
            }
            i++;
        }
        return count;
    }
};