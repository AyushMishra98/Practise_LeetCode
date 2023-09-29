class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<=3)
            return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1;j<n-2;j++){
                if(j>(i+1) && nums[j] == nums[j-1])
                    continue;
                int low=j+1,high=n-1;
                long long temp_sum=target-((long long)nums[i]+(long long)nums[j]);
                while(low<high){
                    long long curr_sum=nums[low]+nums[high];
                    if(curr_sum == temp_sum){
                        res.push_back({nums[i],nums[j],nums[low],nums[high]});
                        while(low<high && nums[low] == nums[low+1]){
                            low++;
                        }
                        while(low<high && nums[high]==nums[high-1]){
                            high--;
                        }
                        low++;
                        high--;
                    }
                    else if(curr_sum > temp_sum)
                        high--;
                    else
                        low++;
                }
            }
        }
        return res;   
    }
};