class Solution {
public:
    vector<vector<int>> res;
    void sets(vector<int>& nums,vector<int>& temp,int idx){
        if(idx > nums.size())
            return;
        res.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            sets(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        sets(nums,temp,0);
        return res;
    }
};