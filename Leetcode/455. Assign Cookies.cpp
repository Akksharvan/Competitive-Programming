static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int findContentChildren (vector<int> &A, vector<int> &B) {
        int R = 0, J = 0; sort(begin(A), end(A)); sort(begin(B), end(B));
        for (int &i : A) { while (J < size(B) && B[J] < i) J++; if (J == size(B)) break; R++; J++; }

        return R;
    }
};