class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_path=0;
        for(int i=0;i<n;i++){
            if(i>max_path)
                return false;
            max_path=max(max_path,i+nums[i]);
        }
        return true;
    }
};