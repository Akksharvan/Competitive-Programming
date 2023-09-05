#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int minimum_lying = N;
    vector<pair<int, int>> information(N);

    for (int i = 0; i < N; i++) {
        char s;
        int n;
        cin >> s >> n;

        if (s == 'G') {
            information[i].first = n;
            information[i].second = 1;
        }
        else {
            information[i].first = n;
            information[i].second = 0;
        }
    }

    sort(information.begin(), information.end());

    for (int i = 0; i < N; i++) {
        int h = information[i].first;
        int lying_cows = 0;

        for (int j = 0; j < N; j++) {
            if (information[j].second) {
                if (h < information[j].first) {
                    lying_cows++;
                }
            }
            else if (!information[j].second) {
                if (h > information[j].first) {
                    lying_cows++;
                }
            }
        }

        minimum_lying = min(minimum_lying, lying_cows);
    }

    cout << minimum_lying << "\n";
    return 0;
}