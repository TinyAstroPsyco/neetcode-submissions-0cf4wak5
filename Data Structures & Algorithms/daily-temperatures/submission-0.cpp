class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     stack<int> deq;
     int size = temperatures.size();
     vector<int> days(size,0);

     for(int i = 0; i<temperatures.size(); i++){
        while(!deq.empty() &&  temperatures[i] > temperatures[deq.top()]){
            days[deq.top()] = i - deq.top();
            deq.pop();
        }

        deq.push(i);
     }    
     return days;
    }
};
