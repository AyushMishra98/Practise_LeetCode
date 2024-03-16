class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i] == 0)
                nums[i]=-1;
        unordered_map<int,int> m;
        int sum=0;
        int res=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum == 0)
                res=i+1;
            if(m.find(sum) != m.end())
                res=max(res,i-m[sum]);
            if(m.find(sum) == m.end())
                m[sum]=i;
        }
        return res;
    }
};