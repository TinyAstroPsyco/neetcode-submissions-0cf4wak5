class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Strategy is star counting length 
        unordered_map<char, int> dataset;

        int length = 0;

        int left = 0;
        int right = 0;
        // dataset.insert({s[left], left});
        while(right < s.length()){
            
            if(dataset.find(s[right]) == dataset.end()){
                dataset.insert({s[right], right});
                right++;
                
            }

            else if(dataset.find(s[right]) != dataset.end()){
                // length = max(length, right-left);
                while(left < dataset[s[right]]) {
                    dataset.erase(s[left]);
                    left++;
                }
                left++; // skip past the duplicate itself
                // left = dataset[s[right]] + 1;
                dataset[s[right]] = right;
                right ++;
                
                
            }
            length = max(length, right - left); // always update here

            

            
        }
        return length;
    }
};
