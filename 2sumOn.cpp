class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numHash; //Number, Index
        
        for (int i = 0; i < nums.size(); i++) {
            int numToFind = target - nums[i];
            
            if (numHash.find(numToFind) != numHash.end()) {
                return {i, numHash[numToFind]};
            }
            numHash[nums[i]] = i; //assign index as mapped value
        }
        return {}; //empty return case if no pair found
    }
};

//Time complexity of unordered_map is O(1), much faster than the other 2sum case.