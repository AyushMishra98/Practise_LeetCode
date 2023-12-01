class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int i=0,j=0;
        int x=0,y=0;
        while(i<w1.size() && j<w2.size()){
            if(w1[i][x] != w2[j][y])
                return false;
            x++;
            y++;
            if(x == w1[i].size()){
                i++;
                x=0;
            }
            if(y == w2[j].size()){
                j++;
                y=0;
            }
        }
        return (i==w1.size() && j==w2.size());
    }
};