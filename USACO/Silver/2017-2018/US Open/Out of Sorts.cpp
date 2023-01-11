#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) { cin >> A[i].first; A[i].second = i; }

	sort(begin(A), end(A), [](const pair<int, int> &x, const pair<int, int> &y)
	{ return ((x.first == y.first) ? x.second < y.second : x.first < y.first); });

	int res = 0;
	for (int i = 0; i < N; i++) res = max(res, (A[i].second - i));

	cout << (res + 1) << "\n";
	return 0;
}