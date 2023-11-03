class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int temp=1;
        for(auto x:target){
            while(x != temp){
                res.push_back("Push");
                res.push_back("Pop");
                temp++;
            }
            res.push_back("Push");
            temp++;
        }
        return res;
    }
};