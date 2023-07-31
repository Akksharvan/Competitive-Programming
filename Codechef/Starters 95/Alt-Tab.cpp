#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N; vector<string> A(N);
	for (string &i : A) cin >> i;

	map<string, int> B;
	for (int i = 0; i < N; i++) B[A[i]] = i;

	priority_queue<pair<int, string>> C;
	for (const pair<string, int>& i : B) {
		pair<int, string> P = { i.second, i.first };
		C.push(P);
	}

	while (!C.empty()) {
		pair<int, string> P = C.top(); C.pop();
		cout << P.second.substr(size(P.second) - 2, 2);
	}

	return 0;
}