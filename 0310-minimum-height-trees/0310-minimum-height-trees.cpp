class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        if(n==1)
            return {0};
        if(n == 2)
            return {0,1};
        vector<int> adj[n];
        int dgre[n];
        fill(dgre,dgre+n,0);
        
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
            dgre[e[i][0]]++;
            dgre[e[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(dgre[i] == 1)
                q.push(i);
        while(n>2){
            int sz=q.size();
            n=n-sz;
            
            while(sz-- >0){
                int idx=q.front();
                q.pop();
            for(auto x:adj[idx]){
                dgre[x]--;
                if(dgre[x] == 1)
                    q.push(x);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};