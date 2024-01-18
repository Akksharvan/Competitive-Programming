class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[0] > target) return 0;
        int L = 0, H = size(nums) - 1;
        
        while (L < H) {
            int M = L + (H - L + 1) / 2;
            if (nums[M] <= target) L = M;
            else H = M - 1;
        }

        if (nums[L] == target) return L;
        else return (L + 1);
    }
};