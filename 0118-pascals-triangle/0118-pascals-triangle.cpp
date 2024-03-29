class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n);
        res[0]={1};
        for(int i=1;i<n;i++){
            res[i].push_back(1);
            for(int j=1;j<i;j++)
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            res[i].push_back(1);
        }
        return res;
    }
};