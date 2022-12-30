#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<multiset<string>> answers(3);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				string s;
				cin >> s;
				answers[i].insert(s);
			}
		}

		for (int i = 0; i < 3; i++) {
			int points = 0;
			for (const string& s : answers[i]) {
				if (i == 0) {
					if (answers[1].count(s) && answers[2].count(s)) {
						continue;
					}
					else if (answers[1].count(s) || answers[2].count(s)) {
						points++;
					}
					else {
						points += 3;
					}
				}
				else if (i == 1) {
					if (answers[0].count(s) && answers[2].count(s)) {
						continue;
					}
					else if (answers[0].count(s) || answers[2].count(s)) {
						points++;
					}
					else {
						points += 3;
					}
				}
				else {
					if (answers[0].count(s) && answers[1].count(s)) {
						continue;
					}
					else if (answers[0].count(s) || answers[1].count(s)) {
						points++;
					}
					else {
						points += 3;
					}
				}
			}

			cout << points << spc;
		}

		cout << nl;
	}
	
	return 0;
}