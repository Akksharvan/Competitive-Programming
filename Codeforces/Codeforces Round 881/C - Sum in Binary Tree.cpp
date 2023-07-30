#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, S = 0; cin >> N;
    while (N) { S += N; N /= 2; }
    cout << S << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
	
	return 0;
}