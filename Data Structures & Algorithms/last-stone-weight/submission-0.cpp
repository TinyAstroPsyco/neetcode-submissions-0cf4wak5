class Solution {
private:
    priority_queue<int> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        for (int s : stones){
            pq.push(s);
        
        }    // Now we have all the stones in the bag, lets sequentially break the stoens
        while((pq.size() > 1)){
            
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();

            if(s1 != s2) pq.push(s1-s2);
        }

        return pq.empty() ? 0 : pq.top();
        
    }
};
