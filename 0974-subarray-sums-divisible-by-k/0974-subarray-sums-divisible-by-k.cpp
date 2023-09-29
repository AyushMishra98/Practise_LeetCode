class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]++;
        int count=0 ,sum=0;
        for(auto x:nums){
            sum+=x;
            if(m[(sum%k +k)%k]>0)
                count+=m[(sum%k +k)%k];
            m[(sum%k +k)%k]++;
        }
        return count;
    }
};