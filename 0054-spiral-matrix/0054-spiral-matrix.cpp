class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int R=mat.size(),C=mat[0].size();
        
        int left=0,right=C-1;
        int top=0,bottom=R-1;
        
        while(left<=right && top<=bottom){
            
            for(int i=left;i<=right;i++)
                res.push_back(mat[top][i]);
            top++;
            
            for(int i=top;i<=bottom;i++)
                res.push_back(mat[i][right]);
            right--;
            
            if(top<=bottom){
                for(int i=right;i>=left;i--)
                    res.push_back(mat[bottom][i]);
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--)
                    res.push_back(mat[i][left]);
                left++;
            }
        }
        return res;
    }
};