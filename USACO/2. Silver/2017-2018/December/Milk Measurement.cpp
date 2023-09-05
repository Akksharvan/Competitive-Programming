#include <bits/stdc++.h>
using namespace std;

struct Entry { int day; int ID; int delta; };
bool day_cmp (const Entry &x, const Entry &y) { return x.day < y.day; }

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, G;
	cin >> N >> G;

	vector<Entry> entries(N);
	for (Entry &entry : entries) cin >> entry.day >> entry.ID >> entry.delta;

	int ans = 0;
	sort(begin(entries), end(entries), day_cmp);

	map<int, int> outputs;
	outputs[G] = N + 1;

	map<int, int> cows;
	for (Entry &entry : entries) cows[entry.ID] = G;

	for (Entry &entry : entries) {
		int prev_max = rbegin(outputs) -> first;
		int prev_max_count = rbegin(outputs) -> second;

		int old_output = cows[entry.ID];
		int new_output = cows[entry.ID] + entry.delta;

		cows[entry.ID] = new_output;
		outputs[new_output]++;

		if (outputs[old_output] == 1) outputs.erase(old_output);
		else outputs[old_output]--;

		int curr_max = rbegin(outputs) -> first;
		if ((curr_max != prev_max
		&& (old_output != prev_max || new_output < curr_max || outputs.count(prev_max) || outputs[new_output] > 1))
		|| (curr_max == prev_max && outputs[prev_max] != prev_max_count)) ans++;
	}

	cout << ans << "\n";
	return 0;
}