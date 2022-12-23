#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int N, Q;
	cin >> N >> Q;

	vector<int> haybales(N);
	for (int& haybale : haybales) {
		cin >> haybale;
	}

	sort(begin(haybales), end(haybales));

	while (Q--) {
		int A, B;
		cin >> A >> B;
		cout << upper_bound(begin(haybales), end(haybales), B) - lower_bound(begin(haybales), end(haybales), A) << nl;
	}

	return 0;
}