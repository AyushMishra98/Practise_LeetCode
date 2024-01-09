class Solution {
public:
    vector<vector<int>> res;
    void DFSRec(vector<int> adj[],int s,int n,vector<int>& temp){
        
        if(s == n-1){
            res.push_back(temp);
            return;
        }
        for(auto x:adj[s]){
            temp.push_back(x);
            DFSRec(adj,x,n,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
            for(auto it:graph[i])
                adj[i].push_back(it);
        vector<int> temp;
        temp.push_back(0);
        DFSRec(adj,0,n,temp);
        return res;
    }
};