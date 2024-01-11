class Solution {
public:
    int myAtoi(string s) {
        bool flag=false,temp=false;
        string str="";
            for(int i=0;i<s.length();i++){
                int n=s[i];
                if((n<48 || n>57) && temp)
                    break;
                else if(s[i]==' ')
                    continue;
                else if(s[i]=='+'){
                    if(temp)
                        break;
                    temp=true;
                }
                else if(s[i]=='-'){
                    if(temp)
                        break;
                    temp=true;
                    flag=true;
                }
                else if(n>=48 && n<=57){
                    str+=s[i];
                    temp=true;
                }
                else{
                    break;
                }
        }
        long res=0;
        for(int i=0;i<str.length();i++){
            res=res*10+(str[i]-'0');

            if(flag){
                if(res<INT_MAX)
                    continue;
                else if(res==INT_MAX)
                    return -INT_MAX;
                else
                    return INT_MIN;
            }
            if(res>=INT_MAX)
                return INT_MAX;
        }
        if(flag)
            res=-res;
        return res;
    }
};