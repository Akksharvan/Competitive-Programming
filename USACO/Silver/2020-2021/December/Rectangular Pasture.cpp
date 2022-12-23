#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

bool pair_second_cmp (pair<int, int>& a, pair<int, int>&b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> cows(N);
	for (int i = 0; i < N; i++) {
		cin >> cows[i].first >> cows[i].second;
	}

	sort(cows.begin(), cows.end(), pair_second_cmp);
	for (int i = 0; i < N; i++) {
		cows[i].second = i + 1;
	}

	sort(cows.begin(), cows.end());
	for (int i = 0; i < N; i++) {
		cows[i].first = i + 1;
	}

	vector<vector<int>> cow_grid(N + 1, vector<int> (N + 1));
	for (const pair<int, int>& cow : cows) {
		cow_grid[cow.first][cow.second] = 1;
	}

	vector<vector<int>> cows_prefix(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cows_prefix[i][j] += cows_prefix[i - 1][j] + cows_prefix[i][j - 1] - cows_prefix[i - 1][j - 1] + cow_grid[i][j];
		}
	}
	
	long long int answer = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int A1 = max(cows[i].first, cows[j].first);
			int B1 = N;

			int a1 = min(cows[i].first, cows[j].first);
			int b1 = max(cows[i].second, cows[j].second) + 1;

			int A2 = max(cows[i].first, cows[j].first);
			int B2 = min(cows[i].second, cows[j].second) - 1;

			int a2 = min(cows[i].first, cows[j].first);
			int b2 = 1;
			
			int A = cows_prefix[A1][B1] - cows_prefix[a1 - 1][B1] - cows_prefix[A1][b1 - 1] + cows_prefix[a1 - 1][b1 - 1];
			int B = cows_prefix[A2][B2] - cows_prefix[a2 - 1][B2] - cows_prefix[A2][b2 - 1] + cows_prefix[a2 - 1][b2 - 1];
			answer += (A + 1) * (B + 1);
		}
	}

	cout << answer + 1 << nl;
	return 0;
}