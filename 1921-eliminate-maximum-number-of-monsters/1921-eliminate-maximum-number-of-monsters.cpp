class Solution {
public:
    int eliminateMaximum(vector<int>& d, vector<int>& s) {
        vector<double> t;
        for(int i=0;i<d.size();i++)
            t.push_back((double)d[i]/s[i]);
        sort(t.begin(),t.end());
        int count=0;
        for(int i=0;i<t.size();i++){
            if(t[i] <= i)
                break;
            count++;
        }
        return count;
    }
};