class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int temp=0,count=0;
        for(int i=1;i<arr.size();i++){
            if(arr[temp] > arr[i])
                count++;
            else{
                temp=i;
                count=1;
            }
            if(count == k)
                return arr[temp];
        }
        return arr[temp];
    }
};