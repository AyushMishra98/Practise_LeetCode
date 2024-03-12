class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        k=n-k;
        vector<int> temp;
        for(int i=0;i<k;i++)
            temp.push_back(nums[i]);
        for(int i=k;i<n;i++)
            nums[i-k]=nums[i];
        for(int i=n-k;i<n;i++)
            nums[i]=temp[i-(n-k)];
    }
};