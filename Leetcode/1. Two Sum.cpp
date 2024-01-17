class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> A;
        vector<int> B;

        for (int i = 0; i < size(nums); i++) {
            if (A.count(target - nums[i])) {
                B.push_back(i);
                B.push_back(A[target - nums[i]]);

                return B;
            }

            A[nums[i]] = i;
        }

        return B;
    }
};