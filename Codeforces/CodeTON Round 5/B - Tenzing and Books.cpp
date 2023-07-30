#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X, Y = 0; cin >> N >> X;

    vector<vector<int>> D(3, vector<int> (N));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            if ((X | D[i][j]) != X) break;
            Y |= D[i][j];
        }
    }

    if (X == Y) cout << "Yes" << "\n";
    else cout << "No" << "\n"; return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
	
	return 0;
}