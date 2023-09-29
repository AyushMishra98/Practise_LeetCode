class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int x1=intervals[0][0],x2=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int y1=intervals[i][0],y2=intervals[i][1];
            if(x2<y1){
                res.push_back({x1,x2});
                x1=y1;
                x2=y2;
            }
            else
                x2=max(x2,max(y1,y2));
        }
        res.push_back({x1,x2});
        return res;
    }
};