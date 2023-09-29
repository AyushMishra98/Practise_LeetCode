class Solution {
public:
    vector<int> prevs,nexts;//prev smaller ,next smaller
    void prevSmaller(vector<int>& nums){
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            while(!s.empty() && nums[s.top()]>=nums[i])
                s.pop();
            if(s.empty())
                prevs[i]=-1;
            else
                prevs[i]=s.top();
            s.push(i);
        }
    }
    void nextSmaller(vector<int>& nums){
        stack<int> s;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i])
                s.pop();
            if(s.empty())
                nexts[i]=n;
            else
                nexts[i]=s.top();
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        prevs.resize(heights.size());
        nexts.resize(heights.size());
        prevSmaller(heights);
        nextSmaller(heights);
        int res=0;
        for(int i=0;i<heights.size();i++){
            res=max(res,(nexts[i]-prevs[i]-1)*heights[i]);
        }
        return res;
    }
};