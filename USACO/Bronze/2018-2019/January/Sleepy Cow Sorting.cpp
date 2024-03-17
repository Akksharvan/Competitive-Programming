#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    
	ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N); for (auto &i : A) cin >> i;

    for (int i = N - 1; i >= 0; i--) {
        if (i == 0) { cout << 0 << "\n"; return 0; }
        if (A[i] < A[i - 1]) { cout << i << "\n"; return 0; }
    }

    return 0;
}
