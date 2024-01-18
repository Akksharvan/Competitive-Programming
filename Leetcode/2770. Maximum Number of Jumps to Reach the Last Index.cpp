class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> DP(size(nums), -1); DP[0] = 0;
        
        for (int j = 1; j < size(nums); j++) {
            for (int i = 0; i < j; i++) {
                if (abs(nums[j] - nums[i]) <= target) DP[j] = max(DP[j], (DP[i] == -1) ? (-1) : (DP[i] + 1));
            }
        }

        return DP[size(nums) - 1];
    }
};