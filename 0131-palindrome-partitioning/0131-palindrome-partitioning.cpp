class Solution {
public:
    vector<vector<string>> res;
        
    bool isPalindrome(int i,int j,string& str){
        while(i<j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void doPartitions(int i,int n,string s,vector<string>& temp){
        if(i == n){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                doPartitions(j+1,n,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        doPartitions(0,s.length(),s,temp);
        return res;
    }
};