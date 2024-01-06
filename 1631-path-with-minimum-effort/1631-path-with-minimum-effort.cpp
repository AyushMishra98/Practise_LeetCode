class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        int x[4]={-1,0,1,0};
        int y[4]={0,1,0,-1};
        
        int m=h.size(),n=h[0].size();
        vector<vector<int>> diff(m,vector<int> (n,INT_MAX));
        
        pq.push({1,{0,0}});
        diff[0][0]=0;
        
        while(!pq.empty()){
            auto r=pq.top();
            pq.pop();
            
            for(int k=0;k<4;k++){
                int i=r.second.first+x[k];
                int j=r.second.second+y[k];
                
                if(i>=0 && i<m && j>=0 && j<n){
                    int newdiff=abs(h[i][j]-h[r.second.first][r.second.second]);
                    int maxdiff=max(newdiff,diff[r.second.first][r.second.second]);
                    if(diff[i][j] > maxdiff){
                        diff[i][j]=maxdiff;
                        pq.push({maxdiff,{i,j}});
                    }
                }
            }
        }
        return diff[m-1][n-1];
    }
};