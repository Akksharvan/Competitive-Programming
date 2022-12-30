#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		multiset<int> arr;
		for (int i = 0; i < n; i++) {
			int number;
			cin >> number;
			arr.insert(number);
		}

		vector<int> answer(n), prefix(n);
		answer[0] = *prev(arr.end());
		prefix[0] = *prev(arr.end());
		arr.erase(prev(arr.end()));

		int last_index;
		for (int i = 1; i < n; i++) {
			multiset<int>::iterator optimal_value_iterator;
			bool optimal_value_set = false;
			int maximum_prefix = prefix[i - 1];

			for (const int& value : arr) {
				if ((prefix[i - 1] | value) > maximum_prefix) {
					optimal_value_iterator = arr.find(value);
					optimal_value_set = true;
					maximum_prefix = (prefix[i - 1] | value);
				}
			}

			if (!optimal_value_set) {
				last_index = i;
				break;
			}
			else {
				answer[i] = *optimal_value_iterator;
				prefix[i] = maximum_prefix;
				arr.erase(optimal_value_iterator);
			}
		}

		while (!arr.empty()) {
			answer[last_index] = *prev(arr.end());
			arr.erase(prev(arr.end()));
			last_index++;
		}

		for (int i = 0; i < n; i++) {
			cout << answer[i] << spc;
		}

		cout << nl;
	}

	return 0;
}