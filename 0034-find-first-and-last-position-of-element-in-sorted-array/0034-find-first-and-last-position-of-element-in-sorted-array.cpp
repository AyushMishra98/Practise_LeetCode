class Solution {
public:
    int first(vector<int>& nums, int t){
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid] == t){
                if(mid == 0 || nums[mid-1]!=t)
                    return mid;
                high=mid-1;
            }
            else if(nums[mid] > t)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
    int last(vector<int>& nums, int t){
        int n=nums.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid] == t){
                if(mid == n-1 || nums[mid+1]!=t)
                    return mid;
                low=mid+1;
            }
            else if(nums[mid] > t)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int t) {
        vector<int> res;
        res.push_back(first(nums,t));
        res.push_back(last(nums,t));
        return res;
    }
};