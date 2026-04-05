class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> seq;
        int arr[2];
        int val1 = 0;
        int val2 = 0;
        int first = true;
        for(string s : tokens){
            
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                
                val2 = stoi(seq.top());
                seq.pop();
                val1 = stoi(seq.top());
                seq.pop(); 
                
                if(s == "+"){
                    seq.push(to_string(val1 + val2));
                }

                else if(s == "-"){
                    seq.push(to_string(val1 - val2));
                }

                else if(s == "*"){
                    seq.push(to_string(val1 * val2));
                }

                else if(s == "/"){
                    seq.push(to_string(val1 / val2));
                }
                
            }
            else seq.push(s);

        }
        int final = stoi(seq.top());
        return final;
    }
};
