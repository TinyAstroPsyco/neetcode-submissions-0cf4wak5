class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> deq;
    vector<int> output;

    for(int i = 0; i < nums.size();i++){
        // adding elements into the deque

        while(!deq.empty() && nums[deq.back()] < nums[i]){
            deq.pop_back();
        } 
        deq.push_back(i);

        if(!deq.empty() && deq.front() < i- k +1) deq.pop_front();

        if(i >= k-1){
            output.push_back(nums[deq.front()]);
        }

    }   
    return output;
    }
};
