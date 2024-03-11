class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> arr(26,0);
        for(auto x:s)
            arr[x%97]++;
        string str="";
        for(auto x:order)
            while(arr[x%97]-->0){
                str+=x;
            }
        for(int i=0;i<26;i++)
            while(arr[i]-->0){
                str+=char(97+i);
            }
        return str;
    }
};