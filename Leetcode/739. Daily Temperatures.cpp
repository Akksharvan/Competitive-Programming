static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> dailyTemperatures (vector<int> &A) {
        int N = size(A); vector<int> R(N, 0); stack<pair<int, int>> B;
        for (int i = 0; i < N; i++) {
            while (!B.empty() && B.top().first < A[i]) {
                pair<int, int> C = B.top(); B.pop();
                R[C.second] = (i - C.second);
            }

            B.push({A[i], i});
        }

        return R;
    }
};