#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);

	int N;
	cin >> N;

	set<int> bessie_cards;
	for (int i = 1; i <= (2 * N); i++) {
		bessie_cards.insert(i);
	}

	set<int> elsie_cards;
	for (int i = 0; i < N; i++) {
		int elsie_card;
		cin >> elsie_card;

		elsie_cards.insert(elsie_card);
		bessie_cards.erase(elsie_card);
	}

	int maximum_points = 0;
	for (const int &elsie_card : elsie_cards) {
		if (bessie_cards.upper_bound(elsie_card) == bessie_cards.end()) {
			bessie_cards.erase(bessie_cards.begin());
		}
		else {
			bessie_cards.erase(bessie_cards.upper_bound(elsie_card));
			maximum_points++;
		}
	}

	cout << maximum_points << nl;
	return 0;
}