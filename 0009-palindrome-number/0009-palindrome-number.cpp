class Solution {
public:
    bool isPalindrome(int x) {
        long int temp=0;
        int n=x;
        
        while(n>0){
            temp=temp*10+n%10;
            n=n/10;
        }
        return (temp == x);
    }
};