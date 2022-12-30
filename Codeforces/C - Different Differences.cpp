#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;

		int f = k;
		while (1 + (((f * f) - f) / 2) > (n - (k - f))) f--;

		set<int> answer;
		int next_number = 1;
		answer.insert(next_number);

		for (int i = 1; i < f; i++) {
			next_number += i;
			answer.insert(next_number);
		}

		while (sz(answer) < k) answer.insert(next_number++);
		for (const int &a : answer) cout << a << spc;
		cout << nl;
	}

	return 0;
}