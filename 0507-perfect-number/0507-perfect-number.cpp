class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1)
            return false;
        
        int sum=1;
        for(int i=2;i*i<=num;i++){
            if(num%i == 0){
                if(i*i == num)
                    sum+=i;
                else
                    sum+=i+num/i;
            }
        }
        return (sum == num);
    }
};