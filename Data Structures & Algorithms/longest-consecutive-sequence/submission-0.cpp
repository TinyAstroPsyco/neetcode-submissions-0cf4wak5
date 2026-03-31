class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest_sequence = 0;
        unordered_set<int> dataset(nums.begin(), nums.end());

        // Now we will iterate thorough the num in nums and start with the head of the sequence
        for (int n: dataset){
            if(dataset.find(n-1) == dataset.end()){
                int current_num = n;
                int current_seq_length = 1;
                while(dataset.find(current_num+1) != dataset.end()){
                    current_num +=1;
                    current_seq_length +=1;
                }
                longest_sequence = max(current_seq_length, longest_sequence);
            }
        }
        return longest_sequence;
    }
};
