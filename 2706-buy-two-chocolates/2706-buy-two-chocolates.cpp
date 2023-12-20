class Solution {
public:
    int buyChoco(vector<int>& p, int money) {
        int i1=0,i2=-1;
        for(int i=1;i<p.size();i++){
            if(p[i]<p[i1]){
                i2=i1;
                i1=i;
            }
            else if(i2==-1 || p[i]<p[i2] || i==i1)
                i2=i;
        }
        return (p[i1]+p[i2]<=money)?(money-(p[i1]+p[i2])):money;
    }
};