class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int n1=0,n2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=n2){
                count1=1;
                n1=nums[i];
            }
            else if(count2==0 && nums[i]!=n1){
                count2=1;
                n2=nums[i];
            }
            else if(nums[i]==n1)
                count1++;
            else if(nums[i]==n2)
                count2++;
            else{
                count1--;
                count2--;
            }
            
        }
        count1=0,count2=0;
        for(auto x:nums){
            if(x==n1)
                count1++;
            else if(x==n2)
                count2++;
        }
        vector<int> res;
        if(count1> n/3)
            res.push_back(n1);
        if(count2> n/3)
            res.push_back(n2);
        return res;
    }
};