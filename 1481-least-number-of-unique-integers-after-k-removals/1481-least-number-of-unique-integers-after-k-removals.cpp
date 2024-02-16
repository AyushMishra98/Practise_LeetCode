class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto x:arr)
            m[x]++;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:m)
            pq.push(x.second);
        
        while(k>0){
            int temp=pq.top();
            pq.pop();
            if(k<temp){
                pq.push(temp-k);
                k=0;
            }
            else{
                k=k-temp;
            }
        }
        return pq.size();
    }
};