class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector<string> res;
        stack<int> s;
        for(int i=1;i<=n;i++)
            s.push(i);
        int sz=t.size();
        
        while(!s.empty() && t[sz-1] != s.top())
            s.pop();
        
        for(int i=sz-1;i>=0;i--){
            while(!s.empty() && t[i]!=s.top()){
                res.push_back("Pop");
                res.push_back("Push");
                s.pop();
            }
            if(s.empty())
                return res;
            res.push_back("Push");
            s.pop();
        }
        while(!s.empty()){
            res.push_back("Pop");
            res.push_back("Push");
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};