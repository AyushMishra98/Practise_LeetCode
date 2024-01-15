class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        unordered_set<int> s;
        unordered_map<int,int> m;
        for(auto x:mat){
            s.insert(x[0]);
            m[x[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto x:m)
           if(x.second == 1)
                ans[1].push_back(x.first);
        for(auto x:s)
            if(m.find(x) == m.end())
                ans[0].push_back(x);
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};