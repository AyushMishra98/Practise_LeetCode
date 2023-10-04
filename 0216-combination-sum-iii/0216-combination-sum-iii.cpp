class Solution {
public:
    vector<vector<int>> res;
    void combinations(int k ,int t,vector<int>& temp,int idx){
        if(k==0 && t==0){
            res.push_back(temp);
            return;
        }
        if(k<0 || idx >9 ||t<0)
            return;
        for(int i=idx;i<=9;i++){
            temp.push_back(i);
            combinations(k-1,t-i,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        combinations(k,n,temp,1);
        return res;
    }
};