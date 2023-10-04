class Solution {
public:
    int titleToNumber(string c) {
        int res=0;
        int temp=1;
        for(int i=c.length()-1;i>=0;i--){
            res+=temp*(c[i]%64);
            if(i!=0)
                temp=temp*26;
        }
        return res;
    }
};