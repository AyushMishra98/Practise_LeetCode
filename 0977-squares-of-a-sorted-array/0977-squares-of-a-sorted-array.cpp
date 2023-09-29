class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int idx=n-1;
        int low=0,high=n-1;
        while(low<=high){
            if(abs(nums[low]) <= abs(nums[high])){
                res[idx]=nums[high]*nums[high];
                high--;
            }
            else{
                res[idx]=nums[low]*nums[low];
                low++;
            }
            idx--;
        }
        return res;
    }
};