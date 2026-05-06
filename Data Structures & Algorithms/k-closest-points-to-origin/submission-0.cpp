class Solution {
private:
    priority_queue<pair<int,int>> pq;

    int distance(int x1, int y1){
        return ((x1*x1) + (y1*y1));
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i = 0; i < points.size(); i++){
            //For each point, we will basically compare the top element in the pq and add the idx.
         
            int x1 = points[i][0];
            int y1 = points[i][1];

            
            pq.push({distance(x1, y1), i});


            if(pq.size() > k) pq.pop();
        }

        // 
        vector<vector<int>> output;
        while(!pq.empty()){
            
            output.push_back(points[pq.top().second]);
            pq.pop();
        }

        return output;
    }
};
