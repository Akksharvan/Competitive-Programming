static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    long long flowerGame (long long N, long long M) {
        long long R = 0; for (long long i = 1; i <= N; i++) {
            if (!(i & 1) && (M & 1)) R += ((M + 1) / 2);
            else R += (M / 2);
        }
        
        return R;
    }
};