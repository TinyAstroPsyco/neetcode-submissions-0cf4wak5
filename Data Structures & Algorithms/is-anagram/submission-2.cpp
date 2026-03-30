#include <unordered_map>
#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {
        //Checking if the string are of same length
        if(s.length() != t.length()) return false;

        // Now lets intilize a array of size 26
        int arr[26] = {0};

        for(int i = 0; i<s.size(); i++){
            arr[s[i] - 'a'] ++;
            arr[t[i] - 'a'] --;
        }

        for(int i = 0; i<26; i++){
            if(arr[i] !=0)
            return false;
        }

        return true;
    }
};
