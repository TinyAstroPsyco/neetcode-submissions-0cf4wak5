class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        int ptr = 0;
        vector<int> output;

        while(ptr < nums.size()){
          

            // if(nums[ptr] >= nums[deq.front()]){
            //     deq.push_front(ptr);
            // }
            while(!deq.empty() && nums[deq.back()] < nums[ptr]){
                deq.pop_back();
            }
            deq.push_back(ptr);

            if(!deq.empty() && deq.front() < ptr - k +1) deq.pop_front();

            if(ptr >= k-1){
                output.push_back(nums[deq.front()]);
            }

            ptr++;

            
        }
        return output;
    }
};
