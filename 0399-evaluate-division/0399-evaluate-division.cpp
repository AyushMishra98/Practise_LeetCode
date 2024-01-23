class Solution {
public:
    double BFS(string& src,string& dst,unordered_map<string,vector<pair<string,double>>>& m){
        if(m.find(src) == m.end() ||m.find(dst) == m.end())
            return -1.0;
        
        queue<pair<string,double>> q;
        q.push({src,1.00});
        
        unordered_set<string> st;
        st.insert(src);
            
        while(!q.empty()){
            string s=q.front().first;
            double val=q.front().second;
            q.pop();
            
            if(s == dst)
                return val;
            
            for(auto x:m[s]){
                if(st.find(x.first) == st.end()){
                    st.insert(x.first);
                    q.push({x.first,val*x.second});
                }
            }
    
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        
        unordered_map<string,vector<pair<string,double>>> m;
        for(int i=0;i<e.size();i++){
            m[e[i][0]].push_back({e[i][1],v[i]});
            m[e[i][1]].push_back({e[i][0],1/v[i]});
        }
        vector<double> res;
        for(int i=0;i<q.size();i++)
            res.push_back(BFS(q[i][0],q[i][1],m));
        return res;
    }
};