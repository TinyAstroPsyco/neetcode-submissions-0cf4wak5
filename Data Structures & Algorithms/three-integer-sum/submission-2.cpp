class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // lets sort the array first
        vector<vector<int>> triplets;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int target  = nums[i] * -1;
            //Lets define 2 ptrs, left and right
            int left = i+1 ;
            int right = nums.size() - 1 ;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                    
                } 
                else if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }

            }
            

        }
        return triplets;

    }
};
