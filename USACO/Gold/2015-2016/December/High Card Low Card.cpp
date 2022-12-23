#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    
	int N;
    cin >> N;

    int points = 0;

    set<int> bessie_cards;
    set<int> bessie_high_cards;
    set<int> bessie_low_cards;
    set<int> elsie_high_cards;
    set<int> elsie_low_cards;
    for (int i = 1; i <= 2 * N; i++) {
        bessie_cards.insert(i);
    }

    for (int i = 0; i < N / 2; i++) {
        int card;
        cin >> card;
        elsie_high_cards.insert(card);
        bessie_cards.erase(card);
    }

    for (int i = 0; i < N / 2; i++) {
        int card;
        cin >> card;
        elsie_low_cards.insert(card * -1);
        bessie_cards.erase(card);
    }

    for (int i = 0; i < N / 2; i++) {
        bessie_low_cards.insert(*begin(bessie_cards) * -1);
        bessie_cards.erase(begin(bessie_cards));
    }

    for (int i = 0; i < N / 2; i++) {
        bessie_high_cards.insert(*begin(bessie_cards));
        bessie_cards.erase(begin(bessie_cards));
    }

    for (const int& elsie_high_card : elsie_high_cards) {
        if (bessie_high_cards.upper_bound(elsie_high_card) != end(bessie_high_cards)) {
            bessie_high_cards.erase(bessie_high_cards.upper_bound(elsie_high_card));
            points++;
        }
        else {
            bessie_high_cards.erase(begin(bessie_high_cards));
        }
    }

    for (const int& elsie_low_card : elsie_low_cards) {
        if (bessie_low_cards.upper_bound(elsie_low_card) != end(bessie_low_cards)) {
            bessie_low_cards.erase(bessie_low_cards.upper_bound(elsie_low_card));
            points++;
        }
        else {
            bessie_low_cards.erase(begin(bessie_low_cards));
        }
    }

    cout << points << nl;
    return 0;
}