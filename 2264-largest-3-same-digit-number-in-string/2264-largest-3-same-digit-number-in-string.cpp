class Solution {
public:
    string largestGoodInteger(string nums) {
        string str="";
        for(int i=0;i<=nums.length()-3;i++)
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                if(str == "")
                    str=nums.substr(i,3);
                else if(str[0] < nums[i])
                    str=nums.substr(i,3);
            }
        return str;
    }
};