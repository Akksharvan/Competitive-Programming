#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x; //bruh wait, the input is n then x, not x then n -walrus

	vector<pair<int, int>> values;
	for (int i = 1; i <= n; i++) {
		int value;
		cin >> value;
		values.push_back({value, i});
	}

	sort(values.begin(), values.end());
	for (int k = 0; k < n; k++) {
		int i = k + 1;
		int j = n - 1;

		bool complete = false;

		while (i < j) {
			long long int sum = (long long) values[k].first + (long long) values[i].first + (long long) values[j].first;
			if (sum == x) {
				complete = true;
				break;
			}
			else if (sum < x) {
				i++;
			}
			else if (sum > x) {
				j--;
			}
		}
		
		if (complete) {
			cout << values[k].second << " " << values[i].second << " " << values[j].second << "\n";
			return 0;
		}
	}

	cout << "IMPOSSIBLE" << "\n";
	return 0;
}
