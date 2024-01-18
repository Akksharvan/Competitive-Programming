static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int hammingWeight (uint32_t N) {
        int R = 0; for (int i = 0; i < 32; i++) R += ((N >> i) & 1); return R;
    }
};