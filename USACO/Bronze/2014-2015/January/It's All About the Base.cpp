#include <bits/stdc++.h>
using namespace std;

long long F (long long X, array<long long, 3> &A) {
    return (A[0] * X * X) + (A[1] * X) + (A[2] * 1);
}

long long G (long long X, array<long long, 3> &B) {
    long long L = 10, H = 15000;
    
    while (L < H) {
        long long M =  L + (H - L) / 2;
        if (F(M, B) >= X) H = M;
        else L = M + 1;
    }

    return L;
}

void solve () {
    string S1, S2; cin >> S1 >> S2;
    array<long long, 3> A{}, B{};

    for (int i = 0; i < 3; i++) A[i] = (S1[i] - '0');
    for (int i = 0; i < 3; i++) B[i] = (S2[i] - '0');

    for (long long i = 10; i <= 15000; i++) {
       if (F(i, A) != F(G(F(i, A), B), B)) continue;
       cout << i << " " << G(F(i, A), B) << "\n"; return;
    }
}

int main() {
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}