class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        
        unordered_map<int,int> m;
        int n=nums.size();
        
        //two pass solution
        for(auto x:nums)
            m[x]++;
        
        for(auto x:m)
            if(x.second > n/3)
                res.push_back(x.first);
     
//         //one pass solution
//         for(auto x:nums){
//             m[x]++;
            
//             if(m[x]>n/3 && res.size()<2){
//                 if(res.empty())
//                     res.push_back(x);
//                 else if(res.back() != x)
//                     res.push_back(x);
//             }
//         }
        
        return res;
    }
};