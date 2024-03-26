class Solution {
public:
        void merge(vector<int> &arr, int low, int mid, int high)
    {
        int temp[high-low+1];
        int idx=0;

        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp[idx++]=arr[i];
                i++;
            }
            else{
                temp[idx++]=arr[j];
                j++;
            }
        }
        while(i<=mid){
            temp[idx++]=arr[i];
            i++;
        }
        while (j <= high) {
            temp[idx++] = arr[j];
            j++;
        }
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];

        // Your code here
    }
    int checkPairs(vector<int> &arr, int low, int mid, int high){
        int cnt=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && arr[i]>2*(long long)arr[right]){
                right++;
            }
            cnt+=(right-(mid+1));
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int l, int r)
    {
        if(l >= r)
            return 0;
            
        int cnt=0;
        int mid=l+(r-l)/2;
        cnt+=mergeSort(arr,l,mid);
        cnt+=mergeSort(arr,mid+1,r);
        cnt+=checkPairs(arr,l,mid,r);
        merge(arr,l,mid,r);
        return cnt;
        //code here
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};