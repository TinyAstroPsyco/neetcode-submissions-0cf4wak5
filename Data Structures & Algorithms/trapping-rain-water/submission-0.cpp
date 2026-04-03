class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft=0;
        int maxRight = 0;
        int vol = 0;
        while(left < right){
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            if(maxLeft < maxRight){
                vol += maxLeft - height[left];
                left ++;
            }
            else{
                vol += maxRight - height[right];
                right --;
            }
        
        }
        return vol;
    }   
};
