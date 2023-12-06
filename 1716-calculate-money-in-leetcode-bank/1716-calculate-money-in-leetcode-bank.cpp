class Solution {
public:
    int totalMoney(int n) {
        int start=0;
        int res=0;
        int week=28;
        while(n>0){
            if(n<7){
                res+=n*start+((n*(n+1))/2);
                n=0;
            }else{
                res+=28+start*7;
                n=n-7;
                start++;
            }
        }
        return res;
    }
};