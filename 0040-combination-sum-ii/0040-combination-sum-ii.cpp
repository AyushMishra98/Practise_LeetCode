class Solution {
public:
    vector<vector<int>> res;
    void Combinations(vector<int>& c, int t ,int idx ,vector<int>& temp){
        if(t == 0){
            res.push_back(temp);
            return;
        }
        if(t<0 || idx>=c.size())
            return;
        for(int i=idx;i<c.size();i++){
            if(i>idx && c[i] == c[i-1])
                continue;
            temp.push_back(c[i]);
            Combinations(c,t-c[i],i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<int> temp;
        Combinations(c,t,0,temp);
        return res;
    }
};