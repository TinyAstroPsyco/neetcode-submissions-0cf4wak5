class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> windowmap;
        unordered_map<char,int> tmap;
        
        int left = 0; 
        int right = 0;
        int need = 0;
        int have = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        string minstr;

        for(char c:t){
            tmap[c] +=1;
        }
        need = tmap.size();

        // Now we compare the window map with the 
        while(right < s.size()){
            windowmap[s[right]] +=1;


            if(windowmap[s[right]] == tmap[s[right]]){
                have++;
            }
            // NOw we start shriniking the window
            while(have == need){
                
                if(right - left + 1 < minLen){
                    // minstr = s.substr(left, right-left+1);
                    minLeft = left;
                    minLen = right - left + 1;
                    minstr = s.substr(left, minLen);

                }


                windowmap[s[left]] -=1;
                if(tmap.count(s[left]) && windowmap[s[left]] < tmap[s[left]]){
                    have --;
                }
                left ++;
            }


            right++;

        }
        return minstr;
    }
};
