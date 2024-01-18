class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.length(),n2=t2.length();

        vector<int> prev(n2+1,0),curr(n2+1,0);
        
//         for(int i=0;i<=n2;i++)
//             prev[i]=0;
        
        for(int idx1=1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                
                if(t1[idx1-1] == t2[idx2-1])
                    curr[idx2]=1+prev[idx2-1];
                else
                    curr[idx2]= max(prev[idx2],curr[idx2-1]);
            }
            prev=curr;
        }
        return prev[n2];
    }
    int minDistance(string word1, string word2) {
        int temp=longestCommonSubsequence(word1,word2);
        int  l1=word1.length(),l2=word2.length();
        return (l1+l2-2*temp);
    }
};