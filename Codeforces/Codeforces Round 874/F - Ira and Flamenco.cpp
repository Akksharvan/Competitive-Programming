#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long F (long long a, long long b) {
	long long r = 1; 
	while (b) {
		if (b & 1) { r *= a; r %= MOD; }
		a = (a * a) % MOD; b >>= 1;
	}

	return (r % MOD);
}

void solve() {
	long long N, M; cin >> N >> M;
	vector<long long> A(N); for (long long &a : A) cin >> a;

	sort(begin(A), end(A));
	vector<long long> B, C; B.push_back(A[0]), C.push_back(0);

	for (long long &a : A) {
		if (a != B[size(B) - 1]) { B.push_back(a); C.push_back(1); }
		else C[size(C) - 1]++;
	}

	long long R = 0, P = 1; queue<long long> D; D.push(1);
	for (int i = 0; i <= min((int) M - 2, (int) size(C)); i++) { P *= C[i]; P %= MOD; D.push(C[i]); }
	
	for (int i = 0; i <= (int) size(B) - M; i++) {
		P *= F(D.front(), MOD - 2); P %= MOD; D.pop();
		P *= C[i + M - 1]; P %= MOD; D.push(C[i + M - 1]);

		if (B[i] + M - 1 == B[i + M - 1]) { R += P; R & MOD; }
	}

	cout << (R % MOD) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}