class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        //Building the freq map of s1
        for(char c : s1){
            map1[c] +=1;
        }

        while(right < s2.size()){
            map2[s2[right]] +=1;

            if(right - left + 1 > s1.size()){
                
                map2[s2[left]] -=1;
                if(map2[s2[left]] == 0) map2.erase(s2[left]);
                left++;
            }

            if(map2 == map1){
                return true;
            }
            
            right++;
             
        }
        return false;
    }
};
