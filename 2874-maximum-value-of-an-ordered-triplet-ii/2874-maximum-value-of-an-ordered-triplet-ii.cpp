class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> prevgrt(n);
        prevgrt[0]=-1;
        int maxileft=nums[0];
        
        vector<int> nxtgrt(n);
        nxtgrt[n-1]=-1;
        int maxi=nums[n-1];
        
        for(int i=1;i<n;i++){
            if(nums[i] >= maxileft){
                maxileft=nums[i];
                prevgrt[i]=-1;
            }
            else
                prevgrt[i]=maxileft;
            
            int idx=n-i-1;
            nxtgrt[idx]=maxi;
            maxi=max(maxi,nums[idx]);
        }
        long long res=0;
        for(int i=1;i<n-1;i++){
            if(nxtgrt[i]!=-1 && prevgrt[i]!=-1)
                res=max(res,(long long)(prevgrt[i]-nums[i])*nxtgrt[i]);
        }
        return res;
    }
};