class Solution {
public:
    string convertToTitle(int n) {
        if(n<27){
            string str="";
            str+=char(n+'A'-1);
            return str;
        }
        string c = "";
        while (n > 0){
            if(n%26 == 0){
                c+='Z';
                n-=1;
            }else{
                c+=(n%26+'A'-1);
            }
            n/=26;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};