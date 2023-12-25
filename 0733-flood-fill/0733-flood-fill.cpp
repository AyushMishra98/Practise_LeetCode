class Solution {
public:
    int x[8]={-1,0,1,0};
    int y[8]={0,1,0,-1};
    void DFS(vector<vector<int>>& img,int i,int j,int color,int val){
        if(i<0 || i>=img.size())
            return;
        if(j<0 || j>=img[0].size())
            return;
        
        if(img[i][j] != val)
            return;
        
        img[i][j]=color;
        
        for(int k=0;k<4;k++)
            DFS(img,i+x[k],j+y[k],color,val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        if(img[sr][sc] != color)
            DFS(img,sr,sc,color,img[sr][sc]);
        return img;
    }
};