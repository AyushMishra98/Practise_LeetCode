class Solution {
public:
    int countSubstrings(string s) {
        int res=0,len=s.length();
        for(int i=0;i<len;i++){
            int l=i,r=i;
            while(l>=0 && r<=len-1){
                if(l==r || s[l]==s[r]){
                    res++;
                    l--;
                    r++;
                }
                else
                    break;
            }
            int L=i,R=i+1;
            while(L>=0 && R<=len-1){
                if(s[L]==s[R]){
                    res++;
                    L--;
                    R++;
                }
                else
                    break;
            }
        }
        return res;
    }
};