#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

	long long N, T = 0; cin >> N;
	vector<pair<long long, long long>> A(N);

	for (pair<long long, long long> &i : A) cin >> i.first >> i.second;
	sort(begin(A), end(A));

	for (pair<long long, long long> &i : A) T = max(T, i.first), T += i.second;
	cout << T << "\n";

	return 0;
}