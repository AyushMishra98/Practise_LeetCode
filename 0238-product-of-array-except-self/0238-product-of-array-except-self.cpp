class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        int p=1,s=1;// p-prefix ,s-suffix
        for(int i=0;i<n;i++){
          //preProduct
          res[i]*=p;
          p*=nums[i];
          //suffProduct
          res[n-i-1]*=s;
          s*=nums[n-i-1];
        }
        return res;
    }
};