class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int n=nums.size();
        
        vector<int> temp(n+1,0);
        for(auto x:nums)
            temp[x]++;
        
        for(int i=1;i<=n;i++)
            if(temp[i] == 0)
                res[1]=i;
            else if(temp[i] == 2)
                res[0]=i;
        return res;
    }
};