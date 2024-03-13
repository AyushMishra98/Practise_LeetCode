class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)
            return 1;
        int low=0,high=n;
        while(low<high){
            int mid=low+(high-low)/2;
            int leftSum=(mid*(mid+1))/2;
            int rightSum=((n*(n+1))/2)-leftSum+mid;
            if(leftSum == rightSum)
                return mid;
            else if(leftSum<rightSum)
                low++;
            else
                high--;
        }
        return -1;
    }
};