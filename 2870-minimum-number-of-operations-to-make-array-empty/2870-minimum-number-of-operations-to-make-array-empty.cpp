class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
        int res=0;
        for(auto x:m){
            if(x.second == 1)
                return -1;
            int val=x.second/3;
            int rem=x.second%3;
            if(rem >0)
                val++;
            res+=val;
        }
        return res;
    }
};