class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int idx;
    SeatManager(int n) {
        idx=1;
    }
    
    int reserve() {
        if(!pq.empty()){
            int temp=pq.top();
            pq.pop();
            return temp;
        }
        idx++;
        return idx-1;
    }
    
    void unreserve(int s) {
        pq.push(s);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */