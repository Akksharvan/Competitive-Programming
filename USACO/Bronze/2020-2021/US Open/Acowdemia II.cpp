#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

bool lexicographical_increasing (string x, string y) {
	for (int i = 0; i < min(sz(x), sz(y)); i++) {
		if (x[i] < y[i]) {
			return true;
		}
		else if (x[i] > y[i]) {
			return false;
		}
	}
	
	if (sz(x) < sz(y)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K, N;
	cin >> K >> N;

	vector<set<int>> Senior_Members(N);
	map<string, int> Member_To_ID;

	for (int ID = 0; ID < N; ID++) {
		string Member;
		cin >> Member;

		Member_To_ID[Member] = ID;
	}

	for (int k = 0; k < K; k++) {
		vector<string> author_list(N);
		
		for (int i = 0; i < N; i++) {
			cin >> author_list[i];
		}

		for (int i = 0; i < N; i++) {
			int j = i;

			while (j + 1 < N && lexicographical_increasing(author_list[j], author_list[j + 1])) {
				j++;
			}

			int r = j + 1;
			int ID = Member_To_ID[author_list[i]];

			while (r < N) {
				Senior_Members[ID].insert(Member_To_ID[author_list[r]]);
				r++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				cout << 'B';
			}
			else if (Senior_Members[i].count(j)) {
				cout << 0;
			}
			else if (Senior_Members[j].count(i)) {
				cout << 1;
			}
			else {
				cout << '?';
			}
		}
		cout << nl;
	}

	return 0;
}