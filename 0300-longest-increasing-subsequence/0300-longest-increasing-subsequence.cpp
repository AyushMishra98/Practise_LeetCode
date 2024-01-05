class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;
    temp.push_back(nums[0]);
    int res=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
            res++;
        }
        else{
            auto idx=lower_bound(temp.begin(),temp.end(),nums[i]);
            temp[idx-temp.begin()]=nums[i];
        }
    }
    return res;
    }
};