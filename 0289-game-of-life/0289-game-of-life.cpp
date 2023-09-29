class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        int m=b.size(),n=b[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                for(int k=0;k<8;k++){

                    int x=i+dx[k] ,y=j+dy[k];
                    
                    if(x<0 || y<0 ||x>=m ||y>=n)
                        continue;
                    
                    if( b[x][y] == 1 || b[x][y] == -1)
                            count++;
                }
                if((count <=1 || count>=4) && (b[i][j] == 1))
                    b[i][j]=-1;
                if(count == 3 && b[i][j]==0)
                    b[i][j]=2;
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                b[i][j]=(b[i][j] > 0)?1:0;
    }
};