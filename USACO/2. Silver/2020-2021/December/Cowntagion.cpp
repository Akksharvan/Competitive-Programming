#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

vector<vector<int>> farms_adjacency_list((int) 1e5);
int days = 0;

void dfs (int farm, int previous_farm) {	
	int ics = 1;

	if (farm == 0) {
		while (ics <= sz(farms_adjacency_list[farm])) {
			ics *= 2;
			days++;
		}
	}
	else {
		while (ics < sz(farms_adjacency_list[farm])) {
			ics *= 2;
			days++;
		}
	}

	for (const int& next_farm : farms_adjacency_list[farm]) {
		if (next_farm != previous_farm) {
			days++;
			dfs(next_farm, farm);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		farms_adjacency_list[a].push_back(b);
		farms_adjacency_list[b].push_back(a);
	}

	dfs(0, -1);
	cout << days << nl;
	return 0;
}