class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ret = 0, ct = 0;
        for (int &n : nums) if (!(n % 2) && !(n % 3)) ret += n, ct++;
        return (ct ? (ret / ct) : 0);
    }
};