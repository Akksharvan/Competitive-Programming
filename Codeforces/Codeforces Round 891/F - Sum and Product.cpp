#include <bits/stdc++.h>
using namespace std;

long long F (long long L, long long H, long long X) {
    while (L < H) {
        long long M = L + (H - L + 1) / 2;
        if ((M * M) <= X) L = M;
        else H = M - 1;
    }

    return L;
}

void solve() {
    int N; cin >> N;

    map<long long, long long> A;
    for (int i = 0; i < N; i++) { int X; cin >> X; A[X]++; }

    int Q; cin >> Q;
    while (Q--) {
        long long X, Y; cin >> X >> Y;
        long long B = F(0, 4e9, ((X * X) - (4 * Y)));

        if ((B * B) != ((X * X) - (4 * Y))) { cout << 0 << " "; continue; }
        if (((X + B) % 2) || ((X - B) % 2)) { cout << 0 << " "; continue; }

        if ((X + B) == (X - B)) cout << ((A[(X + B) / 2] * (A[(X + B) / 2] - 1)) / 2) << " ";
        else cout << (A[(X + B) / 2] * A[(X - B) / 2]) << " ";
    }

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