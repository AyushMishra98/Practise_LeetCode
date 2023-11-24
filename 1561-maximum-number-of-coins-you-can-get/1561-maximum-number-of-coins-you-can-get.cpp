class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(),p.end());
        int count=0;
        int n=p.size();
        for(int i=n/3;i<n-1;i+=2)
            count+=p[i];
        return count;
    }
};