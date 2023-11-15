class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int temp=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i] >=temp+1)
                temp++;
        }
        return temp;
    }
};