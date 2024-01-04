class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
        int count=0;
        for(auto x:m){
            int temp=x.second;
            if(temp == 1)
                return -1;
            
            count+=temp/3;
            temp=temp%3;
            count+=temp/2;
            temp=temp%2;
            
            if(temp == 1)
                count++;
        }
        return count;
    }
};