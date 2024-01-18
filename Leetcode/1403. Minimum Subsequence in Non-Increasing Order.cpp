class Solution {
public:
    vector<int> minSubsequence(vector<int>& A) {
        long long B = accumulate(begin(A), end(A), 0LL), C = 0;
        sort(rbegin(A), rend(A)); vector<int> D;

        for (int &i : A) {
            D.push_back(i); B -= i, C += i;
            if (C > B) break;
        }

        return D;
    }
};