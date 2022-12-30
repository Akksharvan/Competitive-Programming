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
		int n, q;
		cin >> n >> q;

		vector<int> step_heights(n + 1);
		vector<long long int> total_heights(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> step_heights[i];
			total_heights[i] = total_heights[i - 1] + step_heights[i];
		}

		vector<long long int> answers(q);
		vector<pair<int, int>> questions(q);
		for (int i = 0; i < q; i++) {
			cin >> questions[i].first;
			questions[i].second = i;
		}

		sort(questions.begin(), questions.end());
		int l = 0;
		for (int i = 0; i < q; i++) {
			while (l + 1 <= n && step_heights[l + 1] <= questions[i].first) {
				l++;
			}

			answers[questions[i].second] = total_heights[l];
		}

		for (const long long int& answer : answers) {
			cout << answer << spc;
		}

		cout << nl;
	}

	return 0;
}