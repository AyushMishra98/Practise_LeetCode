class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
//         vector<int> res;
        
//         unordered_map<int,int> m;
//         int n=nums.size();
        
//         //two pass solution
//         for(auto x:nums)
//             m[x]++;
        
//         for(auto x:m)
//             if(x.second > n/3)
//                 res.push_back(x.first);
     
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
        
        // return res;
        
        //optimal solution
        vector<int> res;
        
        int n=nums.size();
        int c1=0,e1,c2=0,e2;
        
        for(auto x:nums){
            if(c1 == 0 && x!=e2){
                e1=x;
                c1=1;
            }
            else if(c2 == 0 && x!=e1){
                e2=x;
                c2=1;
            }
            else if(x == e1)
                c1++;
            else if(x == e2)
                c2++;
            else{
                c1--;
                c2--;
            }
        }
        
        int cnt1=0,cnt2=0;
        for(auto x:nums){
            if(x == e1)
                cnt1++;
            else if(x == e2)
                cnt2++;
        }
        if(cnt1 >n/3)
            res.push_back(e1);
        if(cnt2 >n/3)
            res.push_back(e2);
        
        return res;
    }
};