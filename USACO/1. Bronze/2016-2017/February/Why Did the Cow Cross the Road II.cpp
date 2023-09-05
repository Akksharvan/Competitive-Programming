#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
const int A = 65;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    vector<pair<int, int>> points(26, {-1, -1});
    int crossingPairs = 0;
    string paths;

    cin >> paths;

    for (int i = 0; i < 52; i++) {
        int index = int(paths[i]) - A;

        if (points[index].first == -1) {
            points[index].first = i;
        }
        else {
            points[index].second = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if ((points[i].first < points[j].first && points[i].second > points[j].first && points[i].second < points[j].second) || (points[j].first < points[i].first && points[j].second > points[i].first && points[j].second < points[i].second)) {
                crossingPairs++;
            }
        }
    }

    cout << crossingPairs << "\n";

    return 0;
}