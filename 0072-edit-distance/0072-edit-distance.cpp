class Solution {
public:
    int minDistance(string w1, string w2) {
        int m=w1.length(),n=w2.length();
     
        vector<int> prev(n+1,0),curr(n+1,0);
        
        for(int j=0;j<=n;j++)
            prev[j]=j;
        
        for(int i=1;i<=m;i++){
            curr[0]=i;
            for(int j=1;j<=n;j++){
                
                if(w1[i-1] == w2[j-1])
                    curr[j]=prev[j-1];
                else{
                    int insert=curr[j-1];
                    int replace=prev[j-1];
                    int remove=prev[j];
                
                    curr[j]=1+min(insert,min(replace,remove));
            }
            }
            prev=curr;
        }
        return prev[n];
    }
};