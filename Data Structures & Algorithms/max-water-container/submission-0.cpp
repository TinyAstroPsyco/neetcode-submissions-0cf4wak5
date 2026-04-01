class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;
        int left = 0;
        int right = heights.size()-1;
        while(left < right){
            int l_max = min(heights[left] , heights[right]) * (right-left);
            max_water = max(max_water, l_max);
            if(heights[left] < heights[right]){
                left++;
            }
            else right--;
        }
        return max_water;
    }
};
