class Solution {
public:
    int binarySearch(vector<vector<int>>& intervals,int target){
        int low=0,high=intervals.size()-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(intervals[mid][0] == target)
                return mid;
            else if(intervals[mid][0] > target)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pos=binarySearch(intervals,newInterval[0]);
        intervals.insert(intervals.begin()+pos,newInterval);
        return merge(intervals);
    }
};