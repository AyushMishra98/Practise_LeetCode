class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.size()==1)
            return arr[0];
        int count=1;
        int res=0;
        int n=arr.size();
        int i=1;
        while(i<n){
            int temp=1;
            if(arr[i]==arr[i-1] ){
                while(i<n && arr[i]==arr[i-1]){
                temp++;
                i++;
            }
            if(temp > count){
                count=temp;
                res=i;
            }
            }else
                i++;
        }
        return arr[res-1];
    }
};