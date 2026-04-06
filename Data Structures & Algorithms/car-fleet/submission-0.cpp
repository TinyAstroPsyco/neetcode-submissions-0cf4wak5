class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> data(position.size());
        int fleet = 1;
        for(int i =0; i<position.size(); i++){
            data[i]= {position[i], speed[i]};
        }
        // Sorting
        sort(data.begin(), data.end(), greater<pair<int, int>>());
        double target_time = (double)(target - data[0].first)/data[0].second;
        double current_time = 0;
        for(int i = 1; i < position.size();i++){
            current_time = (double)(target - data[i].first)/data[i].second;
            if(target_time - current_time < 0){
                target_time = current_time;
                fleet++;
            }
        }
        return fleet;
    }
};
