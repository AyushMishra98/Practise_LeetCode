class Solution {
public:
    void sortColors(vector<int>& nums) {
        // vector<int> temp(3,0);
        // for(auto x:nums)
        //     temp[x]++;
        // nums.clear();
        // for(int i=0;i<3;i++){
        //     int c=temp[i];
        //     while(c-->0)
        //         nums.push_back(i);
        // }
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};