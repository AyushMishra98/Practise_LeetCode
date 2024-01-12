class Solution {
public:
    //Optimal solution
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            
            for(int j=0;j<n;j++){
                
                if(i == 0 && j == 0)
                    temp[j]=1;
                if(i > 0)
                    temp[j]+=prev[j];
                if(j > 0)
                    temp[j]+=temp[j-1];
            }
            prev=temp;
        }
        return prev[n-1];
    }
};