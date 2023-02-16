#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long int n; cin >> n;
	if ((n * (n + 1)) % 4) cout << "NO" << "\n";
	else {
		cout << "YES" << "\n"; long long int s = 0, t = (n * (n + 1)) / 4;
		set<long long int> a; for (long long int i = 1; i <= n; i++) a.insert(i); vector<long long int> b;

		while (s < t) {
			if (a.find(t - s) == end(a)) { s += *prev(end(a)); b.push_back(*prev(end(a))); a.erase(*prev(end(a))); }
			else { a.erase(a.find(t - s)); b.push_back(t - s); s = t; }
		}

		cout << ((int) a.size()) << "\n";
		for (const long long int &i : a) cout << i << " ";

		cout << "\n" << ((int) b.size()) << "\n";
		for (const long long int &i : b) cout << i << " ";
	}

	cout << "\n";
	return 0;
}