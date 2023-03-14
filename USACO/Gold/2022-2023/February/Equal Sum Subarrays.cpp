#include <bits/stdc++.h>
using namespace std;

struct Subarray { int i; int j; long long int s = 0; };
bool foo (Subarray &x, Subarray &y) { return x.s < y.s; }
bool bar (int i, Subarray &x) { return x.i <= i && i <= x.j; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N; vector<long long> A(N), DP(N + 1); 
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) DP[i] = DP[i - 1] + A[i - 1];

	vector<Subarray> B;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			Subarray b; b.i = i; b.j = j;
			b.s = DP[j + 1] - DP[i]; B.push_back(b);
		}
	}

	sort(begin(B), end(B), foo);

	for (int i = 0; i < N; i++) {
		long long res = LLONG_MAX;
		for (int j = 0; j < (int) B.size() - 1; j++) {
			if ((bar(i, B[j]) && !bar(i, B[j + 1])) || (!bar(i, B[j]) && bar(i, B[j + 1]))) {
				res = min(res, abs(B[j].s - B[j + 1].s));
			}
		}

		cout << res << "\n";
	}

	return 0;
}