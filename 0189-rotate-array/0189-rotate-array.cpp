class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int len=n-k;
        reverse(nums.begin(),nums.begin()+len);
        reverse(nums.begin()+len,nums.end());
        reverse(nums.begin(),nums.end());
    }
};