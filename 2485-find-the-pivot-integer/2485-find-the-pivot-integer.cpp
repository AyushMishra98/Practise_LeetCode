class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)
            return 1;
        int sum=(n*(n+1))/2;
        int curr=0;
        for(int i=1;i<=n;i++){
            curr+=i;
            if(sum-curr+i == curr)
                return i;
        }
        return -1;
    }
};