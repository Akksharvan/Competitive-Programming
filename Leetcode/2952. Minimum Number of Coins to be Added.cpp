static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int minimumAddedCoins(vector<int> &A, int B) {
        sort(begin(A), end(A));
        long long C = 0; int R = 0;
        
        for (int &i : A) {
            while (C + 1 < i) C += (C + 1), R++;
            if (i <= C + 1) C += i;
        }


        while (C < B) C += (C + 1), R++;
        return R;
    }
};