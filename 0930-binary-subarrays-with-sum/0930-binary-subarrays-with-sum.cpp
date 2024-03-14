class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        int sum=0;
        int count=0;
        for(auto x:nums){
            sum+=x;
            if(sum == goal)
                count++;
            if(m.find(sum-goal) != m.end())
                count+=m[sum-goal];
            m[sum]++;
        }
        return count;
    }
};