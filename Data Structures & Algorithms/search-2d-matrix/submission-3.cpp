class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int xmax = matrix[0].size();
        int ymax = matrix.size();

        int mid = 0;
        int midx = 0;
        int midy = 0;
        int midv = 0;

        int left = 0;
        int right = (ymax * xmax) - 1;

        while(left <= right){
            mid = left + (right - left)/2;
            midy = (int)(mid / xmax);
            midx = (int)(mid % xmax);
            midv = matrix[midy][midx];
            if(midv < target){
                left = mid + 1;
            }
            else if(midv > target){
                right = mid - 1;
                  
            }
            else return true;
        }
        return false;
    }
};
