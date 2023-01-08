#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> spottyCows(N, vector<int>(M));
    vector<vector<int>> plainCows(N, vector<int>(M));

    int geneSets = 0;

    for (int i = 0; i < N; i++) {
        string genome;
        cin >> genome;

        for (int j = 0; j < M; j++) {
            if (genome[j] == 'A') {
                spottyCows[i][j] = 0;
            }
            else if (genome[j] == 'T') {
                spottyCows[i][j] = 1;
            }
            else if (genome[j] == 'C') {
                spottyCows[i][j] = 2;
            }
            else if (genome[j] == 'G') {
                spottyCows[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        string genome;
        cin >> genome;

        for (int j = 0; j < M; j++) {
            if (genome[j] == 'A') {
                plainCows[i][j] = 0;
            }
            else if (genome[j] == 'T') {
                plainCows[i][j] = 1;
            }
            else if (genome[j] == 'C') {
                plainCows[i][j] = 2;
            }
            else if (genome[j] == 'G') {
                plainCows[i][j] = 3;
            }
        }
    }

    for (int m1 = 0; m1 < M - 2; m1++) {
        for (int m2 = m1 + 1; m2 < M - 1; m2++) {
            for (int m3 = m2 + 1; m3 < M; m3++) {
                vector<bool> spotted(64);
                bool valid = true;

                for (int i = 0; i < N; i++) {
                    int total = spottyCows[i][m1] * 16 + spottyCows[i][m2] * 4 + spottyCows[i][m3] * 1;
                    spotted[total] = true;
                }

                for (int i = 0; i < N; i++) {
                    int total = plainCows[i][m1] * 16 + plainCows[i][m2] * 4 + plainCows[i][m3] * 1;

                    if (spotted[total]) {
                        valid = false;
                        break;
                    }
                }

                geneSets += valid;
            }
        }
    }

    cout << geneSets << "\n";

    return 0;
}