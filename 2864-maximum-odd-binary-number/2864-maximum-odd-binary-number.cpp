class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int len=s.length();
        if(len <=1)
            return s;
        int i=0;
        while(s[i]!='0' && i<len)
            i++;
        for(int j=i+1;j<len;j++){
            if(s[j] == '1'){
                swap(s[i],s[j]);
                i++;
            }
        }
        swap(s[i-1],s[len-1]);
        return s;
    }
};