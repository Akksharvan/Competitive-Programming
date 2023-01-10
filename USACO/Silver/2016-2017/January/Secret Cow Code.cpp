#include <bits/stdc++.h>
using namespace std;

char foo (string &s, long long int i) {
	long long int l = (long long int) s.size();
	if (i < l) return s[i];
	else {
		while (l < i) l *= 2;
		if (l == i) return foo(s, l - 1);
		else return foo(s, i - (l / 2) - 1);
	}
}

int main() {
	freopen("cowcode.in", "r", stdin);
	freopen("cowcode.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S; cin >> S;
	long long int N; cin >> N;

	cout << foo(S, N - 1) << "\n";
	return 0;
}