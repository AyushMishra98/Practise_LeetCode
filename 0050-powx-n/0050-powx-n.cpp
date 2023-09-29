class Solution {
public:
    double calculatePow(double x,int n){
        if(n==0)
            return 1;
        double temp=calculatePow(x,n/2);
        temp=temp*temp;
        if(n%2==0)
            return temp;
        else 
            return temp*x;
    }
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        else if(n>0)
            return calculatePow(x,n);
        else
            return calculatePow(1/x,n);
    }
};