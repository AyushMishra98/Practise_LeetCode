class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int i1=0,i2=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res[i1]=nums[i];
                i1+=2;
            }
            else{
                res[i2]=nums[i];
                i2+=2;
            }
        }
        return res;
    }
};