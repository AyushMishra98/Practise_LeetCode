class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%3 != 0)
            return {};
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i+=3){
            if(nums[i+2]-nums[i] > k)
                return {};
            else{
                vector<int> temp;
                for(int j=i;j<i+3;j++)
                    temp.push_back(nums[j]);
                res.push_back(temp);
            }
        }
        return res;
    }
};