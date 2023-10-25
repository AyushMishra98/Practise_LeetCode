class Solution {
public:
    int dfs(int n,int k,int parent){
        if(n == 1)
            return parent;
        int temp=pow(2,n-1);
        if(k > temp/2){
            parent=(parent == 0)?1:0;
            return dfs(n-1,k-(temp/2),parent);
        }
        else{
            parent=(parent == 0)?0:1;
            return dfs(n-1,k,parent);
        }
    }
    int kthGrammar(int n, int k) {
        return dfs(n,k,0);
    }
};