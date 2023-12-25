class Solution {
public:
    int count=0;
    void DFSRec(vector<int> adj[],bool vis[],int idx){
        vis[idx]=true;
        for(auto x:adj[idx])
            if(vis[x]==false)
                DFSRec(adj,vis,x);
    }
    //graph may be disconnected,source may  not be given
    void DFS(vector<int> adj[],int v){
        bool vis[v+1];
        memset(vis,false,sizeof(vis));

        for(int i=0;i<v;i++)
            if(vis[i] == false){
                count++;
                DFSRec(adj,vis,i);
            }
    }
    int findCircleNum(vector<vector<int>>& C) {
        int n=C.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(C[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        DFS(adj,n);
        return count;
    }
};