static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int majorityElement(vector<int> &A) {
        sort(begin(A), end(A)); return (A[size(A) / 2]);
    }
};