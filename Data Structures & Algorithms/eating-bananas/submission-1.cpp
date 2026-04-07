class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        int mid = 0;
        
        while(left <= right){
            
            mid = left + (right - left)/2;
            long long hoursneeded = 0;
            for(int n: piles){
                hoursneeded += (n + mid - 1) / mid;
            }
            if(hoursneeded <= h){
                right = mid -1;
            }

            else {
                left = mid + 1;
            }
        }
        return left;
        
    }
};
