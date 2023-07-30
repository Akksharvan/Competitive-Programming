#include <bits/stdc++.h>
using namespace std;

struct Lamp { int a, b; };
bool F (Lamp &x, Lamp &y) { if (x.a == y.a) { return x.b > y.b; } else { return x.a < y.a; } }

void solve() {
	int N; cin >> N;
	vector<Lamp> L(N); for (Lamp &l : L) cin >> l.a >> l.b;
	
	sort(begin(L), end(L), F); queue<Lamp> A;
	for (Lamp &l : L) A.push(l);

	long long R = 0;
	while (!A.empty()) {
		int x = A.front().a, y = x;
		if (x >= size(A)) {
			while (!A.empty()) { R += A.front().b; A.pop(); }
		}
		else {
			while (y && A.front().a == x) { y--; R += A.front().b; A.pop(); }
			while (!A.empty() && A.front().a == x) { A.pop(); }
		}
	}

	cout << R << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}