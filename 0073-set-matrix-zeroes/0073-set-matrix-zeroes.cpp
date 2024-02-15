class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        
        bool flag1=false;
        bool flag2=false;
        
        if(mat[0][0] == 0){
            flag1=true;
            flag2=true;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    if(i==0)
                        flag1=true;
                    if(j==0)
                        flag2=true;
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int j=1;j<n;j++){
            if(mat[0][j] == 0){
                for(int i=1;i<m;i++)
                    mat[i][j]=0;
            }
        }
        for(int i=1;i<m;i++){
            if(mat[i][0] == 0){
                for(int j=1;j<n;j++)
                    mat[i][j]=0;
            }
        }
        if(flag1){
            for(int j=0;j<n;j++)
                mat[0][j]=0;
        }
        if(flag2){
            for(int i=0;i<m;i++)
                mat[i][0]=0;
        }
    }
};