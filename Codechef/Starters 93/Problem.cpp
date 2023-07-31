#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	cout << ((abs(N - M) % 4 == 0 || abs(N - M) % 2 == 0) ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();
    
    return 0;
}