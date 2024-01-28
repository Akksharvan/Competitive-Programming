static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int maximumLength (vector<int> &A) {
        unordered_map<int, int> B;
        long long R = 0; for (int &i : A) B[i]++;
        
        for (auto &[key, val] : B) {
            long long T1 = key, T2 = val, R1 = 1;
            if (T1 == 1) { R = max(R, T2 - ((T2 & 1) ? 0 : 1)); continue; }
            
            while (T1 * T1 <= 1e9 && T2 >= 2 && B.count(T1 * T1)) R1 += 2, T1 *= T1, T2 = B[T1];
            R = max(R, R1);
        }
        
        return R;
    }
};