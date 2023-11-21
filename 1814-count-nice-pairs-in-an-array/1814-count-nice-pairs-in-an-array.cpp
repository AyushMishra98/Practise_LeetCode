class Solution {
public:
    int rev(int n){
        int temp=0;
        while(n>0){
            temp=temp*10+n%10;
            n=n/10;
        }
        return temp;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++)
            arr.push_back(nums[i]-rev(nums[i]));
        unordered_map<int,int> mp;
        int count=0;
        int mod=1e9+7;
        for(auto x:arr){
            count=(count+mp[x])%mod;
            mp[x]++;
        }
        return count;
    }
};