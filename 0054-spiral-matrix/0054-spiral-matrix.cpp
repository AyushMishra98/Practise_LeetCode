#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int t=0,b=mat.size()-1;
        int l=0,r=mat[0].size()-1;
        while(t<=b && l<=r){
            for(int j=l;j<=r;j++)
                res.pb(mat[t][j]);
            t++;
            for(int i=t;i<=b;i++)
                res.pb(mat[i][r]);
            r--;
            
            if(t<=b){
                for(int j=r;j>=l;j--)
                res.pb(mat[b][j]);
            b--;
            }
            
            if(l<=r){
                for(int i=b;i>=t;i--)
                res.pb(mat[i][l]);
            l++;
            }
        }
        return res;
    }
};