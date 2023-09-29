class Solution {
public:
    void transpose(vector<vector<int>>& mat){
        int m=mat.size();
        for(int i=0;i<m;i++)
            for(int j=0;j<i;j++)
                swap(mat[i][j],mat[j][i]);
    }
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        transpose(matrix);
    }
};