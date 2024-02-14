class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp(3,0);
        for(auto x:nums)
            temp[x]++;
        nums.clear();
        for(int i=0;i<3;i++){
            int c=temp[i];
            while(c-->0)
                nums.push_back(i);
        }
    }
};