class Solution {
public:
    bool match(string& str1 ,string &str2){
        vector<int> arr(26,0);
        
        for(int i=0;i<str1.length();i++){
            if(arr[str1[i]-97] == 1)
                return false;
            arr[str1[i]-97]++;
        }
        
        for(int i=0;i<str2.length();i++){
            if(arr[str2[i]-97] == 1)
                return false;
            arr[str2[i]-97]++;
        }
        
        return true;
    }
    int mxLen(int idx,string str,vector<string>& arr){
        if(idx == arr.size())
            return 0;
        
        if(match(arr[idx],str)){
            
            int notTake=mxLen(idx+1,str,arr);
            int take=arr[idx].length()+mxLen(idx+1,str+arr[idx],arr);
            
            return max(take,notTake);
        }
        else
            return mxLen(idx+1,str,arr);
    }
    int maxLength(vector<string>& arr) {
        string str="";
        return mxLen(0,str,arr);
    }
};