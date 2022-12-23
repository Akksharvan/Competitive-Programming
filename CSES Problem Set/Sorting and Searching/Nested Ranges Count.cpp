#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

struct Interval {
	int start, end, index;
	
	Interval () {
		start = 0, end = 0, index = 0;
	}

	Interval (int s, int e, int i) {
		start = s, end = e, index = i;
	}
};

bool cmp (Interval& a, Interval& b) {
	if (a.start == b.start) {
		return a.end > b.end;
	}
	else {
		return a.start < b.start;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t = 0;
	cin >> n;
	
	vector<Interval> ranges(n);
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ranges[i] = Interval(x, y, i);
	}

	vector<Interval> sorted_ranges = ranges;
	sort(begin(sorted_ranges), end(sorted_ranges), cmp);

	vector<int> contained(n), contains(n);
	ost endpoints_one, endpoints_two;
	endpoints_one.insert({sorted_ranges[0].end, t});

	for (int i = 1; i < n; i++) {
		int value = sorted_ranges[i].end;
		contained[sorted_ranges[i].index] = sz(endpoints_one) - endpoints_one.order_of_key({value, 0});
		endpoints_one.insert({value, ++t});
	}

	reverse(begin(sorted_ranges), end(sorted_ranges));
	endpoints_two.insert({sorted_ranges[0].end, t});

	for (int i = 1; i < n; i++) {
		int value = sorted_ranges[i].end;
		contains[sorted_ranges[i].index] = endpoints_two.order_of_key({value + 1, 0});
		endpoints_two.insert({value, ++t});
	}

	for (int i = 0; i < n; i++) {
		cout << contains[i] << spc;
	}

	cout << nl;

	for (int i = 0; i < n; i++) {
		cout << contained[i] << spc;
	}

	return 0;
}