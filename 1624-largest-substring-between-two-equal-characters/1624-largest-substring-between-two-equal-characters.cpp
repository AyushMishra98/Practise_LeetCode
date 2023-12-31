class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> m;
        int maxi=-1;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i]) != m.end())
                maxi=max(maxi,i-m[s[i]]-1);
            else
                m[s[i]]=i;
        }
        return maxi;
    }
};