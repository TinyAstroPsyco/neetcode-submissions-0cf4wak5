class Solution {
public:
    bool isValid(string s) {
        // Lets use a stack to deal with this
        stack<char> checker;
        if(s.length() %2 !=0 || s[0] == ']'  || s[0] == ')' || s[0] == '}') return false; 
        for(int i = 0; i< s.length(); i++){
            if(s[i] == '[') checker.push(']');
            else if(s[i] == '(') checker.push(')');
            else if(s[i] == '{') checker.push('}');

            else {
                if(checker.empty() || s[i] != checker.top()) return false;
                checker.pop();
            }
        }
        if(!checker.empty()) return false;
        else return true;

    }
};
