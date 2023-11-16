class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].length();
        vector<int> temp(pow(2,n),false);
        for(int i=0;i<nums.size();i++)
            temp[stoi(nums[i],nullptr,2)]=true;
        int i=0;
        for(i;i<temp.size();i++)
            if(temp[i] == false)
                break;
        string res="";
        while(i>0){
            res+=(i%2+'0');
            i=i/2;
        }
        while(res.length() != nums[0].length()){
            res+='0';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};