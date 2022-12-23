#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> movies(n);
	for (pair<int, int>& movie : movies) {
		cin >> movie.second >> movie.first;
	}

	sort(begin(movies), end(movies));

	int movies_watched = 0;
	multiset<int> end_times;

	for (int i = 0; i < k; i++) {
		end_times.insert(0);
	}

	for (const pair<int, int>& movie : movies) {
		if (end_times.upper_bound(movie.second) != begin(end_times)) {
			end_times.erase(prev(end_times.upper_bound(movie.second)));
			end_times.insert(movie.first);
			movies_watched++;
		}
	}

	cout << movies_watched << nl;
	return 0;
}