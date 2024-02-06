class Solution {
public:
    string minWindow(string s, string t) {                
        int remain = t.size();
        //to keep track of frequency of element
        unordered_map<char, int> m;
        for(char c : t)
            m[c]++;
    
        int start = 0, len = 0;
        int left=0,right=0;
        while(right<s.size()) {
            char curr = s[right];
        
            m[curr]--;
            if(m[curr] >= 0)
                remain--;
        
        while(remain == 0) {
            if(len == 0 || right - left + 1 < len)  {
                start = left;
                len = right - left + 1;
            }
            
            curr = s[left];
            
            m[curr]++;
            if(m[curr] > 0)
               remain++;
            
            left++;
        }
        right++;
    }
    return s.substr(start, len);
}
};