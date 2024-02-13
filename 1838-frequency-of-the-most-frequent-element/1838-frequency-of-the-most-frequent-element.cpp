class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int maxi=0;
        int low=0;
        long sum=0;
        
        for(int high=0;high<nums.size();high++){
            long lar=nums[high];
            sum+=lar;
            
            while((high-low+1)*lar > sum+k){
                sum-=nums[low];
                low++;
            }
            maxi=max(maxi,high-low+1);
        }
        return maxi;
    }
};