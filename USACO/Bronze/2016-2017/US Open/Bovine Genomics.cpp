#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<string> spottyCows(N);
    vector<string> plainCows(N);
    vector<bool> positions(M, true);

    int positionsCounter = 0;

    for (int i = 0; i < N; i++) {
        string genome;
        cin >> genome;

        spottyCows[i] = genome;
    }

    for (int i = 0; i < N; i++) {
        string genome;
        cin >> genome;

        plainCows[i] = genome;
    }

    for (int s = 0; s < N; s++) {
        for (int m = 0; m < M; m++) {
            if (positions[m]) {
                char spottyGene = spottyCows[s][m];

                for (string p : plainCows) {
                    if (spottyGene == p[m]) {
                        positions[m] = false;
                    }
                }
            }
            else {
                continue;
            }
        }
    }

    for (int m = 0; m < M; m++) {
        if (positions[m]) {
            positionsCounter++;
        }
    }

    cout << positionsCounter << "\n";

    return 0;
}