class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < (int) nums.size(); i++) nums[i] += nums[i - 1];
        return nums;
    }
};