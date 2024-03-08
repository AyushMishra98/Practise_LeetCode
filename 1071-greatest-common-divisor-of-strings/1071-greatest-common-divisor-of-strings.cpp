class Solution {
public:
    
    bool check(string txt,string pat){
        int l1=txt.length(),l2=pat.length();
        int i=0;
        while(i<l1){
            for(int j=0;j<l2;j++){
                if(txt[i] != pat[j])
                    return false;
                i++;
            }
        }
        return (i==l1);
    }
    string gcdOfStrings(string str1, string str2) {
        int l1=str1.length(),l2=str2.length();
        string mini,maxi;
        if(l1<l2){
            mini=str1;
            maxi=str2;
        }
        else{
            mini=str2;
            maxi=str1;
        }
        for(int i=mini.length();i>0;i--)
            if(check(maxi,mini.substr(0,i)) && check(mini,mini.substr(0,i)))
                return mini.substr(0,i);
        return "";
    }
};