class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> DP(size(nums1), vector<int> (2, 1)); DP[0][0] = 1; DP[0][1] = 1;
        
        for (int i = 1; i < size(nums1); i++) {
            if (nums1[i] >= nums1[i - 1]) DP[i][0] = max(DP[i][0], DP[i - 1][0] + 1);
            if (nums1[i] >= nums2[i - 1]) DP[i][0] = max(DP[i][0], DP[i - 1][1] + 1);
            
            if (nums2[i] >= nums2[i - 1]) DP[i][1] = max(DP[i][1], DP[i - 1][1] + 1);
            if (nums2[i] >= nums1[i - 1]) DP[i][1] = max(DP[i][1], DP[i - 1][0] + 1);
        }
        
        int R = 0; for (int i = 0; i < size(nums1); i++) R = max(R, max(DP[i][0], DP[i][1]));
        return R;
    }
};