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
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n=a.size();
        
        DisjointSet ds(n);
        
        unordered_map<string,int> mapMailNode;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<a[i].size();j++){
                string mail=a[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end())
                    mapMailNode[mail]=i;
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        
        vector<string> merge[n];
        
        for(auto it:mapMailNode){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            merge[node].push_back(mail);
        }
        
        vector<vector<string>> res;
        
        for(int i=0;i<n;i++){
            if(merge[i].size() == 0)
                continue;
            
            vector<string> temp;
            temp.push_back(a[i][0]);
            sort(merge[i].begin(),merge[i].end());
            for(auto x:merge[i])
                temp.push_back(x);
            
            res.push_back(temp);
        }
        return res;
    }
};