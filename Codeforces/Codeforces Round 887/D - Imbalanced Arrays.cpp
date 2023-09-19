#include <bits/stdc++.h>
using namespace std;

int F (int L, int H, int A, vector<int> &B) {
    while (L < H) {
        int M = L + (H - L + 1) / 2;
        if (B[M - 1] + A > 0) L = M;
        else H = M - 1;
    }

    return L;
}

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    vector<pair<int, int>> B; vector<int> C(N);
    for (int i = 0; i < N; i++) B.push_back({A[i], i});

    sort(begin(B), end(B));
    int L = 0, R = N - 1, X = 0;

    while (L <= R) {
        if (L && B[L].first == B[L - 1].first) { C[B[L].second] = C[B[L - 1].second]; L++; continue; }
        while ((N - 1) - R < B[L].first && !C[B[R].second]) { C[B[R].second] = N - X; R--; }

        if (L > R) break;

        C[B[L].second] = (-1 * N) + (X + (C[B[(min(R + 1, N - 1))].second] == N - X ? 1 : 0));
        X += (C[B[min(R + 1, N - 1)].second] == N - X ? 2 : 1); L++;
    }

    vector<int> D = C;
    sort(rbegin(D), rend(D));

    for (int i = 0; i < N; i++) {
        if (F(0, N, C[i], D) == A[i]) continue;
        cout << "NO" << "\n"; return;
    }

    cout << "YES" << "\n";
    for (int &i : C) cout << i << " ";

    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}