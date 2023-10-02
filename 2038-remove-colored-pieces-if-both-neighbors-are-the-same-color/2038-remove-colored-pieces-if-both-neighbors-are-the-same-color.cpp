class Solution {
public:
    bool winnerOfGame(string c) {
        int n=c.size();
        int countA=0,countB=0;
        int i=0 ,count=0;
        while(i<n){
            if(c[i] == 'A'){
                while(i<n && c[i] == 'A'){
                    i++;
                    count++;
                }
                if(count>=3)
                    countA+=count-2;
            }
            else{
                while(i<n && c[i] == 'B' ){
                    i++;
                    count++;
                }
                if(count>=3)
                    countB+=count-2;
            }
            count=0;
        }
        return (countA > countB)?true:false;
    }
};