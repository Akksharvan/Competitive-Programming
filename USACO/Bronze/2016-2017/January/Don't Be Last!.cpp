#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    map<string, int> cows = {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};
    int N;
    int M = 1e5;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string cow_name;
        int cow_milk;

        cin >> cow_name >> cow_milk;
        cows[cow_name] += cow_milk;
    }

    for (const auto& cow_pair : cows) {
        M = min(M, cow_pair.second);
    }

    vector<pair<string, int>> not_last_cow;

    for (const auto& cow_pair : cows) {
        if (cow_pair.second > M) {
            if (not_last_cow.size() > 0) {
                if (cow_pair.second < not_last_cow[0].second) {
                    not_last_cow.clear();
                    not_last_cow.push_back(cow_pair);
                }
                else if (cow_pair.second == not_last_cow[0].second) {
                    not_last_cow.push_back(cow_pair);
                }
            }
            else {
                not_last_cow.push_back(cow_pair);
            }
        }
    }

    if (not_last_cow.size() == 0 || not_last_cow.size() > 1) {
        cout << "Tie" << "\n";
    }
    else {
        cout << not_last_cow[0].first << "\n";
    }

    return 0;
}