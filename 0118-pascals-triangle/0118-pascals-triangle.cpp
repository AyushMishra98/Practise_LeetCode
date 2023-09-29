class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n);
        res[0].push_back(1);
        n--;
        int idx=0;
        while(n-- > 0){
            res[idx+1].push_back(1);
            for(int j=1;j<res[idx].size();j++)
                res[idx+1].push_back(res[idx][j]+res[idx][j-1]);
            res[idx+1].push_back(1);
            idx++;
        }
        return res;
    }
};