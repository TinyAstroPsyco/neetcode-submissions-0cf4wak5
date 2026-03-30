class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Hashmap
        unordered_map<int, int> data;
        for(int i=0; i<nums.size(); i++){
            data[nums[i]]++;
        }

        // Now we have the hashmap built we will try to store it in the priority queue and retrive it
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto const& [num, value] : data){
            pq.push({value, num});
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        vector<int> final;
        while(!pq.empty()){
            final.push_back(pq.top().second);
            pq.pop();
        }
        return final;
    }
};
