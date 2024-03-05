class Solution {
public:
    int minimumLength(string s) {
        int low=0,high=s.length()-1;
        while(low<high && s[low]==s[high]){
            int i=low;
            while(i<s.length() &&s[low] == s[i]){
                i++;
            }
            low=i;
            int j=high;
            while(j>=0 && s[j] == s[high]){
                j--;
            }
            high=j;
        }
        if(low<=high)
            return (high-low+1);
        return 0;
    }
};