class Solution {
public:
    vector<int> res;
    void topologicalSort(vector<int> adj[],int v){
    int indgre[v];
    memset(indgre,0,sizeof(indgre));
        
    for(int i=0;i<v;i++)
        for(auto x:adj[i])
            indgre[x]++;
        
    queue<int> q;
    
    for(int i=0;i<v;i++)
        if(indgre[i] == 0)
            q.push(i);
    
        while(!q.empty()){
        int temp=q.front();
        q.pop();
        
        res.push_back(temp);
        
        for(auto x:adj[temp]){
            indgre[x]--;
            if(indgre[x] == 0)
                q.push(x);
        }
        
    }
}
//T.C=O(V+E)
//S.C=O(V)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
            for(auto x:graph[i])
                adj[x].push_back(i);
        topologicalSort(adj,n);
    
        sort(res.begin(),res.end());
        return res;
    }
};