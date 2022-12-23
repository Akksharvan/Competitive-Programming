#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

bool cmp (pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<pair<int, int>> ranges(n);
	for (pair<int, int>& range : ranges) {
		cin >> range.first >> range.second;
	}

	vector<pair<int, int>> sorted_ranges = ranges;
	sort(begin(sorted_ranges), end(sorted_ranges), cmp);

	set<pair<int, int>> contained;
	set<pair<int, int>> container;

	int maximum = sorted_ranges[0].second;

	for (int i = 1; i < n; i++) {
		if (sorted_ranges[i].second <= maximum) {
			contained.insert(sorted_ranges[i]);
		}
		else {
			maximum = max(maximum, sorted_ranges[i].second);
		}
	}

	reverse(begin(sorted_ranges), end(sorted_ranges));
	int minimum = sorted_ranges[0].second;

	for (int i = 1; i < n; i++) {
		if (sorted_ranges[i].second >= minimum) {
			container.insert(sorted_ranges[i]);
		}
		else {
			minimum = min(minimum, sorted_ranges[i].second);
		}
	}

	for (int i = 0; i < n; i++) {
		if (container.count(ranges[i])) {
			cout << 1 << spc;
		}
		else {
			cout << 0 << spc;
		}
	}

	cout << nl;

	for (int i = 0; i < n; i++) {
		if (contained.count(ranges[i])) {
			cout << 1 << spc;
		}
		else {
			cout << 0 << spc;
		}
	}

	return 0;
}