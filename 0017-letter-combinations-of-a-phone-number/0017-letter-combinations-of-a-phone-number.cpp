class Solution {
public:
    void combinations(string d,string str, string m[],int idx,vector<string>& res){
    if(idx == d.length()){
        res.push_back(str);
        return;
    }
    string temp=m[d[idx]-'0'];
    for(int i=0;i<temp.length();i++)
        combinations(d,str+temp[i],m,idx+1,res);
}
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0)
            return res;
        string m[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        combinations(digits,"",m,0,res);
        return res;
    }
};