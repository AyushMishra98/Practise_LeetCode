class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> after(n+1,0),curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--){
                
                int len=after[prev_idx+1];
                if(prev_idx == -1 || nums[idx]>nums[prev_idx])
                    len=max(len,1+after[idx+1]);
                
                curr[prev_idx+1]=len;   
            }
            after=curr;
        }
        return after[0];
    }
};