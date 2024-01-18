class Solution {
public:
    string longestCommonSubsequence(string t1, string t2) {
        int n1=t1.length(),n2=t2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        for(int i=0;i<=n1;i++)
            dp[i][0]=0;
        
        for(int i=0;i<=n2;i++)
            dp[0][i]=0;
        
        for(int idx1=1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                
                if(t1[idx1-1] == t2[idx2-1])
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                else
                    dp[idx1][idx2]= max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        int len=dp[n1][n2];
        string str="";
        
      int i=n1,j=n2;
      while(i>0 && j>0){
      if(t1[i-1] == t2[j-1]){
        str+=t1[i-1];
        i--;j--;
      }
      else if(dp[i-1][j] > dp[i][j-1]){
        str+=t1[i-1];
        i--;
      }
      else{
        str+=t2[j-1];
        j--;
      }
      }
        
        while(i>0){
            str+=t1[i-1];
            i--;
        }
        while(j>0){
            str+=t2[j-1];
            j--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return longestCommonSubsequence(str1,str2);
    }
};