class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int count=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] <= k){
                s.insert(nums[i]);
            }
            count++;
            if((int)s.size() == k)
                break;
        }
        return count;
    }
};