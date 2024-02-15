class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=0;
        unordered_set<int> s(nums.begin(),nums.end());
        
        for(auto x:s){
            
            int curr=1;
            if(s.find(x-1) == s.end()){
                while(s.count(x+curr))
                    curr++;
            }
            
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};