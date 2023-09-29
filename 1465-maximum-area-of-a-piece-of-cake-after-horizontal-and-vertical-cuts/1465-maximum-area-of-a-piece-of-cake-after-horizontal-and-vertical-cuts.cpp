class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        sort(ho.begin(),ho.end());
        sort(ve.begin(),ve.end());
        int n1=ho.size(),n2=ve.size();
        int maxh=max(ho[0],h-ho[n1-1]);
        for(int i=1;i<n1;i++)
            maxh=max(maxh,ho[i]-ho[i-1]);
        int maxv=max(ve[0],w-ve[n2-1]);
        for(int i=1;i<n2;i++)
            maxv=max(maxv,ve[i]-ve[i-1]);
        int temp=1000000007;
        return ((long long)(maxv%temp)*(maxh%temp))%temp;
    }
};