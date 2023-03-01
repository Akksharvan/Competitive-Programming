#include <bits/stdc++.h>
using namespace std;

long long int foo (long long int n) {
	if (n == (long long int) 1) return (long long int) 1;
	else return (n * foo(n - 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;

	vector<int> H(N); multiset<int> L;
	for (int i = 0; i < N; i++) cin >> H[i];

	for (int i = 0; i < N; i++) {
		int l; cin >> l;
		L.insert(l);
	}

	sort(rbegin(H), rend(H));

	long long int res = 1;
	for (int i = 0; i < N; i++) {
		int p = N - distance(begin(L), L.lower_bound(H[i]));
		res *= (p - i);
	}

	cout << res << "\n";
	return 0;
}