class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n){
                int low=j+1,high=n-1;
                
                while(low<high){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[low]+nums[high];
                    
                    if(sum == target){
                        res.push_back({nums[i],nums[j],nums[low],nums[high]});
                        
                        int element1=nums[low];
                        low++;
                        while(low<n && nums[low] == element1){
                            low++;
                        }
                        
                        int element2=nums[high];
                        high--;
                        while(high>j && nums[high] == element2){
                            high--;
                        }
                    }
                    else if(sum<target)
                        low++;
                    else
                        high--;
                }
                
                int element3=nums[j];
                j++;
                while(j<n && nums[j] == element3){
                    j++;
                }
            }
            
            int element4=nums[i];
            i++;
            while(i<n && nums[i] == element4){
                i++;
            }
        }
        return res;
    }
};