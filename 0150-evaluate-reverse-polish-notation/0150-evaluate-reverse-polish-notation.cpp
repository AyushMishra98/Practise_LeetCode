class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto x:tokens){
            if(x != "+" && x != "-" && x != "*" && x != "/"){
                s.push(stoi(x));
            }
            else {
                int t1=s.top();
                s.pop();
                int t2=s.top();
                s.pop();
                if(x == "+")
                    s.push(t1+t2);
                else if(x == "-")
                    s.push(t2-t1);
                else if(x == "*")
                    s.push(t1*t2);
                else
                    s.push(t2/t1);
            }
        }
        return s.top();
    }
};