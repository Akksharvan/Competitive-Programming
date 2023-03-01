#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

long long int factorial (long long int n) {
	if (n == (long long int) 1) {
		return (long long int) 1;
	}
	else {
		return (n * factorial(n - 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> heights(N);
	multiset<int> limits;
	for (int i = 0; i < N; i++) {
		cin >> heights[i];
	}

	for (int i = 0; i < N; i++) {
		int limit;
		cin >> limit;
		limits.insert(limit);
	}

	sort(heights.rbegin(), heights.rend());

	long long int w = 1;
	for (int i = 0; i < N; i++) {
		int p = N - distance(limits.begin(), limits.lower_bound(heights[i]));
		w *= (p - i);
	}

	cout << w << nl;
	return 0;
}