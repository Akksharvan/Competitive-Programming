#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> DP(2, vector<int> (N + 1, 0));
    fill(begin(DP[0]), end(DP[0]), INT_MIN);

    for (int i = 1; i <= N; i++) {
        DP[1][i] = max(DP[1][i - 1], i + DP[0][A[i]]);
        DP[0][A[i]] = max(DP[0][A[i]], 1 - i + DP[1][i - 1]);
    }

    cout << DP[1][N] << "\n";
    return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
	
	return 0;
}