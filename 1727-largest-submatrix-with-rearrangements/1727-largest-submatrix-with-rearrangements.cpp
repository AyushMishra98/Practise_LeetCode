class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(i>0 && mat[i][j] == 1)
                    mat[i][j]+=mat[i-1][j];
            vector<int> temp=mat[i];
            sort(temp.begin(),temp.end(),greater());
            for(int i=0;i<n;i++)
                ans=max(ans,temp[i]*(i+1));
        }
        return ans;
    }
};