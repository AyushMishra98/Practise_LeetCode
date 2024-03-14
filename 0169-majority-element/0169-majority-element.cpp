class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int element,count=0;
        for(auto x:nums){
            if(count == 0){
                element=x;
                count=1;
            }
            else if(x == element)
                count++;
            else
                count--;
        }
        return element;
        // int count1=0;
        // for(auto x:nums)
        //     if(x == element)
        //         count1++;
        // return (count1> (n/2))?element:-1;
    }
};