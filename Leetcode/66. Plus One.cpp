class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = 0; reverse(begin(digits), end(digits));
        while (index < size(digits) && digits[index] == 9) { digits[index] = 0; index++; }

        if (index == size(digits)) digits.push_back(1);
        else digits[index]++;

        reverse(begin(digits), end(digits));
        return digits;
    }
};