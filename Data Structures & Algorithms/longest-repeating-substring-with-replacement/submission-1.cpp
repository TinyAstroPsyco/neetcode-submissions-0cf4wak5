class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mapp;
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int length = 0;

        for(right = 0; right < s.size(); right ++){
            

            //Now we will need to increment the frequency
            mapp[s[right]] +=1;
            maxFreq = max(maxFreq, mapp[s[right]]);


            // checking if the window is in valid range
            
            if(((right - left + 1) - maxFreq) > k){
                mapp[s[left]] -=1;
                left++;
            }
            //Calculate the length 
            length = max(length, (right - left + 1));
        }
        return length;
    }
};
