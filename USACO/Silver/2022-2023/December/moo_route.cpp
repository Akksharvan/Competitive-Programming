#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N; string res;
	cin >> N;

	vector<int> A(N);
	for (int &a : A) cin >> a;

	int T = 0; int pos = 0;
	for (int &a : A) T += a;

	while (T--) {
		if (pos == 0) { res += 'R'; A[pos]--; pos++; }
		else if (pos == N) { res += 'L'; A[pos - 1]--; pos--; }
		else if (res[(int) res.length() - 1] == 'R') {
			if (A[pos] > A[pos - 1]) { res += 'R'; A[pos]--; pos++; }
			else { res += 'L'; A[pos - 1]--; pos--; }
		}
		else {
			if (A[pos - 1] > A[pos]) { res += 'L'; A[pos - 1]--; pos--; }
			else { res += 'R'; A[pos]--; pos++; }
		}
	}

	cout << res << "\n";
	return 0;
}