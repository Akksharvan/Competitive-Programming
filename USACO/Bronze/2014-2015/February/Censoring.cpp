#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

	string S, T, R;
	cin >> S >> T;

	for (int i = 0; i < size(S); i++) {
		R += S[i]; if (size(R) < size(T)) continue;
		if (R.substr(size(R) - size(T)) == T) R.resize(size(R) - size(T));
	}

	cout << R << "\n";
	return 0;
}