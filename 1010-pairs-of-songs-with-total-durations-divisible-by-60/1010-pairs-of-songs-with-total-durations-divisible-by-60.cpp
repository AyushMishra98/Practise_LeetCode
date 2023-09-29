class Solution {
public:
    int countPairs(vector<int>& t){
        if(t.size() < 2)
            return 0;
        int count=0;
        unordered_map<int,int> m;
        for(int i=0;i<t.size();i++){
            if(t[i] == 0 && m.find(0)!=m.end())
                count+=m[0];
            else if(m.find(60-t[i]) !=m.end())
                count+=m[60-t[i]];
            m[t[i]]++;
        }
        return count;
    }
    int numPairsDivisibleBy60(vector<int>& t) {
        //after taking modulo it will be reduced to pair with given sum
        for(int i=0;i<t.size();i++)
            t[i]=t[i]%60;
        return countPairs(t);
    }
};