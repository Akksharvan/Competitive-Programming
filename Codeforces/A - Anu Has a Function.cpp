#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int &x : a) cin >> x;

	int optimal = 0;
	for (int i = 0; i <= 30; i++) {
		set<int> activated;
		for (int &x : a) if ((x >> i) & 1) activated.insert(x);
		if ((int) activated.size() == 1) optimal = *activated.begin();
	}

	for (int i = 0; i < n; i++) if (a[i] == optimal) swap(a[0], a[i]);
	for (int &x : a) cout << x << " ";
	
	cout << "\n";
	return 0;
}