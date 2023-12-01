class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        string str1="",str2="";
        for(int i=0;i<w1.size();i++)
            str1+=w1[i];
        for(int i=0;i<w2.size();i++)
            str2+=w2[i];
        return (str1==str2);
    }
};