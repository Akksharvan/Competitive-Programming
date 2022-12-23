#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<char>> answer_key(3);
	multiset<int> answer_count;
	multiset<int> guess_count;

	int green_squares = 0;
	int yellow_squares = 0;

	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < 3; j++) {
			answer_key[i].push_back(s[j]);
			answer_count.insert(s[j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < 3; j++) {
			if (s[j] == answer_key[i][j]) {
				answer_count.erase(answer_count.find(s[j]));
				green_squares++;
			} else {
				guess_count.insert(s[j]);
			}
		}
	}

	for (char c : guess_count) {
		if (answer_count.count(c) > 0) {
			answer_count.erase(answer_count.find(c));
			yellow_squares++;
		}
	}

	cout << green_squares << "\n" << yellow_squares << "\n";
	return 0;
}