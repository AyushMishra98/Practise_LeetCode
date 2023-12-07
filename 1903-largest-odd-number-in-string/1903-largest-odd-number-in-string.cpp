class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.length()-1;
        for(i;i>=0;i--)
            if((num[i]-'0')%2 != 0)
                break;
        return num.substr(0,i+1);
    }
};