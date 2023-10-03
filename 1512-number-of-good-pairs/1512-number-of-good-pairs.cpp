class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int res=0;
        for(auto x:nums){
            if(m.find(x)!=m.end())
                res+=m[x];
            m[x]++;
        }
        return res;
    }
};