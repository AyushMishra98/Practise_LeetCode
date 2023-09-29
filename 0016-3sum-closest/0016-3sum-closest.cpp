class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closestsum=1000000000;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int low=i+1,high=n-1;
            while(low<high){
            int sum=nums[i]+nums[low]+nums[high];
            if(sum == target)
                return sum;
            if(abs(target-sum)<abs(target-closestsum))
                closestsum=sum;
            if(sum>target)
                high--;
            else
                low++;
            }
        }
    return closestsum;
    }
};