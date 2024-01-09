class DisjointSet{
    public:
    vector<int> size,parent;

    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
            parent[i]=i;
    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n=e.size();
        DisjointSet ds(n+1);
        for(auto it:e){
            if(ds.findUPar(it[0]) == ds.findUPar(it[1]))
                return {it[0],it[1]};
            else
                ds.unionBySize(it[0],it[1]);
        }
        return {-1,-1};
    }
};