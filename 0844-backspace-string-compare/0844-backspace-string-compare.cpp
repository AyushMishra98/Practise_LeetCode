class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string new_s="",new_t="";
        int count=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='#')
                count++;
            else{
                if(count>0)
                    count--;
                else
                    new_s+=s[i];
            }
        }
        count=0;
        for(int i=t.length()-1;i>=0;i--){
            if(t[i]=='#')
                count++;
            else{
                if(count>0)
                    count--;
                else
                    new_t+=t[i];
            }
        }
        return (new_s==new_t);
    }
};