#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Cow {
    vector<int> performance;
    Cow() {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout); 

    int K, N;
    cin >> K >> N;

    vector<Cow> cow_vector(N);
    vector<pair<int, int>> pairs;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            int index;
            cin >> index;
            index--;

            int score = N - j;
            cow_vector[index].performance.push_back(score);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool consistent_pair = true;

            for (int k = 0; k < K; k++) {
                if (cow_vector[i].performance[k] <= cow_vector[j].performance[k]) {
                    consistent_pair = false;
                }
            }

            if (consistent_pair) {
                pairs.push_back({i, j});
            }
        }
    }

    cout << pairs.size() << "\n";

    return 0;
}