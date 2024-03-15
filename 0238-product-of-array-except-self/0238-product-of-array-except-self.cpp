class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        // vector<int> res1(n,1),res2(n,1);
        // for(int i=1;i<n;i++){
        //     res1[i]=res1[i-1]*nums[i-1];
        // }
        // for(int i=n-2;i>=0;i--){
        //     res2[i]=res2[i+1]*nums[i+1];
        // }
        // for(int i=0;i<n;i++)
        //     res1[i]=res1[i]*res2[i];
        // return res1;
        vector<int> res(n,1);
        for(int i=1;i<n;i++)
            res[i]=res[i-1]*nums[i-1];
        
        int temp=nums[n-1];
        for(int i=n-2;i>0;i--){
            res[i]=res[i]*temp;
            temp=temp*nums[i];
        }
        res[0]=temp;
        return res;
    }
};