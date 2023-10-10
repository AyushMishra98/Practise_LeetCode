class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        //take care of n its nums.size() not temp.size()
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> temp;
        for(auto x:s)
            temp.push_back(x);
        
        sort(temp.begin(),temp.end());
        
        int res=INT_MAX;
        
        for(int i=0;i<temp.size();i++){
            int maxi=temp[i]+(n-1);
            int idx=upper_bound(temp.begin(),temp.end(),maxi)-temp.begin();
            
            int curr=idx-i;
            res=min(res,n-curr);
        }
        return res;
    }
};