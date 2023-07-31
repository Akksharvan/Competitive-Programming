#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, X; cin >> N >> X;
	cout << ((N * X >= 10000 &&  N * X < 100000) ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();
    
    return 0;
}