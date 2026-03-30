#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Lets store the numbers and their indexes in a hashmap
        std::unordered_map<int,int> data;
        for(int i = 0; i<nums.size(); i++){
            if(data.count(target - nums[i]))
            {
                int key = target - nums[i];
                return {data[key], i};
            }
            data.insert({nums[i],i});     
        } 
    }
};
