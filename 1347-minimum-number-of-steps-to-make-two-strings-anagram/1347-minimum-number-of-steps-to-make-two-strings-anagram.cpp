class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            arr[s[i]-97]++;
            arr[t[i]-97]--;
        }
        int count=0;
        for(int i=0;i<26;i++)
            count+=max(0,arr[i]);
        return count;
    }
};