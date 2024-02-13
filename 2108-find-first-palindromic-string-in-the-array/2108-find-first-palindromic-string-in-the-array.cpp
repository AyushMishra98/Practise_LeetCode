class Solution {
public:
    bool palindrome(string& str,int low,int high){
        if(low>=high)
            return true;
        if(str[low]!=str[high])
            return false;
        return palindrome(str,low+1,high-1);
    }
    string firstPalindrome(vector<string>& words) {
        for(auto x:words)
            if(palindrome(x,0,x.size()-1))
                return x;
        return "";
    }
};