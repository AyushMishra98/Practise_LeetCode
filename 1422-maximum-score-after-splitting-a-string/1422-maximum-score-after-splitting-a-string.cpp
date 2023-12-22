class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int ones=0;
        for(int i=0;i<n;i++)
            if(s[i] == '1')
                ones++;
        int zeros=0;
        int res=0;
        for(int i=0;i<n-1;i++){
            if(s[i] == '1')
                ones--;
            else
                zeros++;
        res=max(res,zeros+ones);
        }
        return res;
    }
};