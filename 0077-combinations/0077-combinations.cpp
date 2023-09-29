class Solution {
public:
    vector<vector<int>> res;
    void combinations(int idx,int n,int k,vector<int>& temp){
        if(k==0){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            combinations(i+1,n,k-1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(k==0)
            return {};
        vector<int> temp;
        combinations(1,n,k,temp);
        return res;
    }
};