class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // I want to add a priority queue here, it wil naturally store the lowest one above
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int n : nums){
            pq.push(n);
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};
