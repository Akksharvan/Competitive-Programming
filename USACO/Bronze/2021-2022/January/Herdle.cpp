#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<char>> A(3);
	multiset<int> AC, BC; int GS = 0, YS = 0;

	for (int i = 0; i < 3; i++) {
		string s; cin >> s;
		for (int j = 0; j < 3; j++) A[i].push_back(s[j]), AC.insert(s[j]);
	}

	for (int i = 0; i < 3; i++) {
		string s; cin >> s;

		for (int j = 0; j < 3; j++) {
			if (s[j] == A[i][j]) AC.erase(AC.find(s[j])), GS++;
			else BC.insert(s[j]);
		}
	}

	for (char c : BC) {
		if (AC.count(c) > 0) AC.erase(AC.find(c)), YS++;
	}

	cout << GS << "\n" << YS << "\n";
	return 0;
}