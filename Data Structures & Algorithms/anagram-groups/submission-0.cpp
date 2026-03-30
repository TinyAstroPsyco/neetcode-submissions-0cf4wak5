class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        vector<vector<string>> final;
        for (string str: strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end()); //So we will sort it first.
            group[sorted].push_back(str);
        }
        // Now our sorted_strs should contain all the sorted strings. Now we will iterate over them angain and compare them and add it to a sub vector.
        for(auto& pair: group){
            final.push_back(pair.second);
        }
        return final;
    }
};
