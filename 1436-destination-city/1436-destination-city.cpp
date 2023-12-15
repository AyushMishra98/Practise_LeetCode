class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,vector<string>> m;
        for(auto x:paths){
            m[x[0]].push_back(x[1]);
            m[x[1]];
        }
        for(auto x:m)
            if(x.second.size()<1)
                return x.first;
        return "";
    }
};