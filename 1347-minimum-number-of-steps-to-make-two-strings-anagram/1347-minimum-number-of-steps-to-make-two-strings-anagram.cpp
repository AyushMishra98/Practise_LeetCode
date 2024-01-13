class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++)
            arr[(int)s[i]-97]++;
        int count=0;
        for(int i=0;i<t.length();i++){
            if(arr[t[i]-97] >0)
                arr[t[i]-97]--;
            else
                count++;
        }
        return count;
    }
};