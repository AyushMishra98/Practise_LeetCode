class Solution {
public:
    int count(string s){
        int temp=0;
        for(int i=0;i<s.length();i++)
            if(s[i] == '1')
                temp++;
        return temp;
    }
    int numberOfBeams(vector<string>& b) {
        int x=0;
        int res=0;
        
        for(int i=0;i<b.size();i++){
            int temp=count(b[i]);
            if(temp != 0){
                if(x == 0)
                    x=temp;
                else{
                    res+=x*temp;
                    x=temp;
                }
            }
        }
        return res;
    }
};