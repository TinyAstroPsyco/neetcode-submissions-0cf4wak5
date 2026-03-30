class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // First we will iterate over the vector and then put that into a hashmap
        // Creating a hashmap
        unordered_map<string, vector<string>> data;
        for(int i = 0; i<strs.size(); i++){
            string tmp_str = strs[i];
            sort(tmp_str.begin(), tmp_str.end());
            data[tmp_str].push_back(strs[i]);

        }
        vector<vector<string>> final;
        for(auto pair : data){
            final.push_back(pair.second);
        }
        return final;
    }
};
