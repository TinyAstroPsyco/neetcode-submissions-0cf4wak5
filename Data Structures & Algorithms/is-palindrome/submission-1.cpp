class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        // We will use the 2 ptr approach, one left and one right ptr both pointing to chars
        int right = s.length() - 1;
        int left = 0;
        while(left < right){
            // Now we only need to point to the alpphanumeric values.
            while(left < right && !isalnum(s[left])){
                left++;
            }

            while(left < right && !isalnum(s[right])){
                right--;
            } 

            // Now lets compare the characters
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        // return newStr == string(newStr.rbegin(), newStr.rend());
        return true;
    }
};