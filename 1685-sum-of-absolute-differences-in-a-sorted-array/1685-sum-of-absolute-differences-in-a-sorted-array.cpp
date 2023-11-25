class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        int temp=0;
        for(auto x:nums)
            temp+=x;
        int begin=0;
        for(int i=0;i<n;i++){
            temp=temp-nums[i];
            int curr=temp-(n-i-1)*nums[i];
            curr+=i*nums[i]-begin;
            res[i]=curr;
            begin+=nums[i];
        }
        return res;
    }
};