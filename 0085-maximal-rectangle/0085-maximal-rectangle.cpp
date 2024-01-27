class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int> s;
        
        int maxA=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || h[s.top()] >= h[i])){
                
                int height=h[s.top()];
                s.pop();
                
                int width;
                if(s.empty())
                    width=i-0;
                else
                    width=i-s.top()-1;
                
                maxA=max(maxA,height*width);
            }
            s.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int> temp(n,0);
        int maxA=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == '0')
                    temp[j]=0;
                else
                    temp[j]++;
            }
            maxA=max(maxA,largestRectangleArea(temp));
        }
        return maxA;
    }
};