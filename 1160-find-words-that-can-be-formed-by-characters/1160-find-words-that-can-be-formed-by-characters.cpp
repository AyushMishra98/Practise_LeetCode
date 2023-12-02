class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> m,temp;
        for(auto x:chars)
            m[x]++;
        int res=0;
        for(auto x:words){
        temp=m;
            int count=0;
            int i=0;
            for(i;i<x.length();i++){
                if(temp.find(x[i]) == temp.end())
                    break;
                else if(temp[x[i]] <= 0)
                    break;
                else{
                    temp[x[i]]--;
                    count++;
                }
            }
            if(i == x.length())
                res+=count;
        }
        return res;
    }
};