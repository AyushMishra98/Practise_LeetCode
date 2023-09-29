class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0,n=height.size();
        int low=0,high=n-1;
        while(low<high){
            int temp=0;
            if(height[low]<=height[high]){
                temp=(high-low)*height[low];
                low++;
            }
            else{
                temp=(high-low)*height[high];
                high--;
            }
            res=max(res,temp);
        }
        return res;
    }
};