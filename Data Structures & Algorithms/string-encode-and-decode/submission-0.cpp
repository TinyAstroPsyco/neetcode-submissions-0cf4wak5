class Solution {
public:

    string encode(vector<string>& strs) {
    string encoded_str;
    for(string s : strs){
        // We will first add the length of the string at the start.
        string len_str = to_string(s.length());
        // Now we will add the padding at the star of the string.
        string padding = string(3 - len_str.length(), '0') + len_str;
        encoded_str +=padding + s;
    }
    return encoded_str;
    }

    vector<string> decode(string s) {
        // We will decoded it based on the length, that is the first 3 characters.
        int i = 0;
        vector<string> decoded_string;
        while(i < (int)s.length()){
            string len_string = s.substr(i, 3); //this will give us the '000' character lenght
            int string_length = stoi(len_string); //this will give the value in int
            i += 3;
            string sub_str = s.substr(i, string_length);
            decoded_string.push_back(sub_str);
            i += string_length;
        }
        
        return decoded_string;

    }
};
