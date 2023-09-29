class Solution {
public:
    bool  isCycle(vector<int> adj[],int v){
        int indgre[v];
        memset(indgre,0,sizeof(indgre));
        for(int i=0;i<v;i++)
            for(auto x:adj[i])
                indgre[x]++;

        queue<int> q;
        for(int i=0;i<v;i++)
            if(indgre[i] == 0)
                q.push(i);
        int count=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto x:adj[temp]){
                indgre[x]--;
                if(indgre[x] == 0)
                    q.push(x);
            }
            count++;
        }
        return (count!= v);
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for(int i=0;i<p.size();i++)
            adj[p[i][1]].push_back(p[i][0]);
        return !isCycle(adj,n);
    }
};