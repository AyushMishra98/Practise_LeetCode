class Solution {
public:
    vector<int> res;
    //Based on kahn's BFS based algorithm
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
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for(int i=0;i<p.size();i++)
            adj[p[i][1]].push_back(p[i][0]);
        topologicalSort(adj,n);
        if((int)res.size() != n)
            return {};
        return res;
    }
};