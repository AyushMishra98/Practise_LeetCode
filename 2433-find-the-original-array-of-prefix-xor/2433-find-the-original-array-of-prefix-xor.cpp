class Solution {
public:
    vector<int> findArray(vector<int>& p) {
        int n=p.size();
        for(int i=n-2;i>=0;i--)
            p[i+1]=p[i]^p[i+1];
        return p;
    }
};