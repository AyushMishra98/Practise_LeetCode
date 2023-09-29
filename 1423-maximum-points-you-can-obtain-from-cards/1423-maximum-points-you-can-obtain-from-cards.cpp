class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int winSize=n-k;
        int totalSum=0;
        for(auto x:c)
            totalSum+=x;
        int minSum=0,sum=0;
        int i=0;
        for(i;i<winSize;i++)
            sum+=c[i];
        minSum=sum;
        for(i;i<n;i++){
            sum+=c[i]-c[i-winSize];
            minSum=min(minSum,sum);
        }
        return totalSum-minSum;
    }
};