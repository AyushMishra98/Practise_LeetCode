class Solution {
public:
    
    void reverse(string& s,int low,int high){
        while(low<high)
            swap(s[low++],s[high--]);
    }
    string reverseWords(string s) {
        int n=s.length();
        int start=0;
        for(int end=0;end<n;end++)
            if(s[end]==' '){
                reverse(s,start,end-1);
                start=end+1;
            }
        reverse(s,start,n-1);
        return s;
    }
};