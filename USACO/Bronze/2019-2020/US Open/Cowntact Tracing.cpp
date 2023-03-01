#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    ios::sync_with_stdio(false);
	  cin.tie(nullptr);

    int N, T; string S;
    cin >> N >> T >> S;

    vector<bool> I(N); for (int i = 0; i < N; i++) I[i] = ((S[i] == '1') ? 1 : 0);
    vector<array<int, 3>> H(T); for (array<int, 3> &h : H) cin >> h[0] >> h[1] >> h[2];

    array<int, 3> res{0, INT_MAX, 0}; sort(begin(H), end(H));
    for (int i = 0; i < N; i++) {
        bool G = 0; if (!I[i]) continue;
        for (int K = 0; K <= T; K++) {
            vector<bool> B(N); B[i] = 1; vector<int> C(N + 1);
            for (array<int, 3> &h : H) {
                if (B[h[1] - 1]) C[h[1]]++;
                if (B[h[2] - 1]) C[h[2]]++;
                if (B[h[1] - 1] && C[h[1]] <= K) B[h[2] - 1] = 1;
                if (B[h[2] - 1] && C[h[2]] <= K) B[h[1] - 1] = 1;
            }

            if (I == B) { G = 1; res[1] = min(res[1], K); res[2] = max(res[2], K); }
        }

        if (G) res[0]++;
    }

    cout << res[0] << " " << res[1] << " " << ((res[2] == T) ? ("Infinity") : (to_string(res[2]))) << "\n";
    return 0;
}