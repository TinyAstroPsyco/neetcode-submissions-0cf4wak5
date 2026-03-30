class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> data;
        for(int i=0; i<nums.size(); i++){
            if((data.count(target - nums[i])))
            {
                int key = target-nums[i];
                return {data[key], i};              
            }
            data.insert({nums[i],i});
            
        }
        return {0,0};
    }
};
