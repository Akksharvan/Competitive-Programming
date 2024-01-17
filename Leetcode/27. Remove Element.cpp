static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int removeElement(vector<int> &A, int T) {
        sort(begin(A), end(A), [T](int &x, int&y) {
            return ((x == T ? INT_MAX : x) < (y == T ? INT_MAX : y));
        });

        int N = size(A), K = 0; for (int i = 0; i < N; i++) {
            if (A[i] == T) break; K++;
        }

        return K;
    }
};