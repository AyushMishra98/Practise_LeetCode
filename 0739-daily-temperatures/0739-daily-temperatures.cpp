class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> res(n,0);
        
        stack<int> s;
        for(int i=0;i<n;i++){
             while(!s.empty() && t[s.top()] < t[i]){
                    int j=s.top();
                    s.pop();
                    
                    res[j]=i-j;
                }
                s.push(i);
        }
        return res;
    }
};