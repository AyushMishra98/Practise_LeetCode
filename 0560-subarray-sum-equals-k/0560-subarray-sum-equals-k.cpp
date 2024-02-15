class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        int res=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum == k)
                res++;
            
            if(m.count(sum-k))
                res+=m[sum-k];
            
            m[sum]++;
        }
        return res;
    }
};