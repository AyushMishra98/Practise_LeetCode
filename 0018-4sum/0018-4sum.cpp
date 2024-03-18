class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> store;
        
        int  n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_set<long long> s;
                for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    
                    long long element=target-sum;
                    if(s.find(element) != s.end()){
                        vector<int> temp={nums[i],nums[j],nums[k],(int)element};
                        sort(temp.begin(),temp.end());
                        store.insert(temp);
                    }
                    s.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> res(store.begin(),store.end());
        return res;
    }
};