#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);

	int N, K; cin >> N >> K;
	string s; cin >> s; cout << s;

	int ret = (int) s.size();
	for (int i = 1; i < N; i++) {
		string s; cin >> s; ret += (int) s.size();
		if (ret > K) ret = (int) s.size(), cout << "\n" << s;
		else cout << " " << s;
	}

	return 0;
}