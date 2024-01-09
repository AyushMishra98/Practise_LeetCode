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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        //step1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0)
                    continue;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+dc[k];
                    if(newr<0 || newr>=n || newc<0 || newc>=n || grid[newr][newc] == 0)
                        continue;
                    
                    int node=i*n+j;
                    int newNode=newr*n+newc;
                    ds.unionBySize(node,newNode);
                }
            }
        }
        //step2
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    continue;
                unordered_set<int> s;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+dc[k];
                    if(newr<0 || newr>=n || newc<0 || newc>=n || grid[newr][newc] == 0)
                        continue;
                    
                    int newNode=newr*n+newc;
                    s.insert(ds.findUPar(newNode));
                    
                }
                int temp=1;
                for(auto x:s)
                    temp+=ds.size[x];
                res=max(res,temp);
            }
        }
        for(int i=0;i<n*n;i++)
            res=max(res,ds.size[i]);
        return res;
    }
};