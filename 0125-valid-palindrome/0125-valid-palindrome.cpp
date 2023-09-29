class Solution {
public:
    bool valid(int n){
        return ((n>=97 && n<=122) || (n>=48 && n<=57));
    }
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        if(s.length()<=1)
            return true;
        int low=0,high=s.length()-1;
        while(low<high){
            bool flag1=valid(s[low]),flag2=valid(s[high]);
            if(!flag1)
                low++;
            else if(!flag2)
                high--;
            else{
                if(s[low]!=s[high])
                    return false;
                low++;
                high--;
            }
        }
        return true;
    }
};