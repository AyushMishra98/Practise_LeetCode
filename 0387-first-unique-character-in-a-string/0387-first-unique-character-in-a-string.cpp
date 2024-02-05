class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26,0);
        for(auto x:s)
            count[x%97]++;
        for(int i=0;i<s.length();i++)
            if(count[s[i]%97] == 1)
                return i;
        return -1;
    }
};