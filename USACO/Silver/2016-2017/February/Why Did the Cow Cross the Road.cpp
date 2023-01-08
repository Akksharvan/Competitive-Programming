#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int C, N;
	cin >> C >> N;

	vector<int> chickens(C);
	for (int &chicken : chickens) cin >> chicken;

	vector<pair<int, int>> cows(N);
	for (pair<int, int> &cow : cows) cin >> cow.first >> cow.second;

	sort(chickens.begin(), chickens.end());
	sort(cows.begin(), cows.end());

	priority_queue<int, vector<int>, greater<int>> pcows;

	int ret = 0;
	int cow_pos = 0;

	for (int chicken : chickens) {
		while (cow_pos < N && cows[cow_pos].first <= chicken) pcows.push(cows[cow_pos].second), cow_pos++;
		while (!pcows.empty() && pcows.top() < chicken) pcows.pop();
		if (!pcows.empty()) pcows.pop(), ret++;
	}

	cout << ret << "\n";
	return 0;
}