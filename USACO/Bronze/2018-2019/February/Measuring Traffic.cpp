#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N; vector<array<int, 3>> A(N);
	for (array<int, 3> &a : A) {
		string s; cin >> s >> a[1] >> a[2];
		if (s == "on") a[0] = 0;
		else if (s == "off") a[0] = 1;
		else a[0] = 2;
	}

	int a = -999999999, b = 999999999;
	for (int i=N-1; i>=0; i--) {
		if (A[i][0] == 2) { a = max(a, A[i][1]); b = min(b, A[i][2]); }
		if (A[i][0] == 1) { a += A[i][1]; b += A[i][2]; }
		if (A[i][0] == 0) { a -= A[i][2]; b -= A[i][1]; a = max(0, a); }
	}

	cout << a << " " << b << "\n";
		
	a = -999999999, b = 999999999;
	for (int i=0; i<N; i++) {
		if (A[i][0] == 2) { a = max(a, A[i][1]); b = min(b, A[i][2]); }
		if (A[i][0] == 0) { a += A[i][1]; b += A[i][2]; }
		if (A[i][0] == 1) { a -= A[i][2]; b -= A[i][1]; a = max(0, a); }
	}

	cout << a << " " << b << "\n";
	return 0;
}