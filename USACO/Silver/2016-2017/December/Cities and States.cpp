#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	map<string, int> ret;
	long long int res = 0;

	for (int i = 0; i < N; i++) {
		string city, state;
		cin >> city >> state;

		string key = state + city.substr(0, 2);
		string lock = city.substr(0, 2) + state;

		if (ret.count(key) && key != lock) res += ret[key];
		ret[lock]++;
	}

	cout << res << "\n";
	return 0;
}