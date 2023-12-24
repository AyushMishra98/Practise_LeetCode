class Solution {
public:
    int minOperations(string s) {
        int c0=0,c1=0;
        for(int i=0;i<s.length();i++){
            //starting from zero
            if((s[i] == '1' && i%2 == 0) || (s[i] == '0' && i%2 != 0))
                c0++;
            //starting from 1
            if((s[i] == '0' && i%2 == 0) || (s[i] == '1' && i%2 != 0))
                c1++;
        }
        return min(c0,c1);
    }
};