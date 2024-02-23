class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(int i=0;i<f.size();i++)
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            
            int u=p.first;
            int x=p.second.first;
            int cost=p.second.second;
            
            if(u>k)
                continue;
            
            
            for(auto r:adj[x])
               if(dist[r.first]>cost+r.second && u<=k){
                   dist[r.first]=cost+r.second; 
                   q.push({u+1,{r.first,dist[r.first]}});
               }
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};