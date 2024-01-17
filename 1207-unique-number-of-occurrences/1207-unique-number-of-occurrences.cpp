class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto x:arr)
            m[x]++;
        int n=m.size();
        unordered_set<int> s;
        for(auto x:m)
            s.insert(x.second);
        return (n == s.size());
        
    }
};