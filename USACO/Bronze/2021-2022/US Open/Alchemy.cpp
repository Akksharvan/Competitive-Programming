#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool valid = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N;

    vector<int> metals(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> metals[i + 1];
    }

    cin >> K;

    vector<vector<int>> recipes(N + 1);
    for (int i = 0; i < K; i++) {
        int L, M;
        cin >> L >> M;

        vector<int> recipe_pieces(M);
        for (int j = 0; j < M; j++) {
            cin >> recipe_pieces[j];
        }

        recipes[L] = recipe_pieces;
    }

    while (true) {
        vector<int> needed_metals(N + 1);

        for (int i = N; i >= 1; i--) {
            if (i == N) {
                if (recipes[i].size() != 0) {
                    for (const int& metal : recipes[i]) {
                        if (metals[metal] > 0) {
                            metals[metal]--;
                        }
                        else {
                            needed_metals[metal]++;
                        }
                    }
                }
                else {
                    valid = false;
                    break;
                }
            }
            else if (needed_metals[i] > 0) {
                if (recipes[i].size() != 0) {
                    for (int j = 0; j < needed_metals[i]; j++) {
                        for (const int& metal : recipes[i]) {
                            if (metals[metal] > 0) {
                                metals[metal]--;
                            }
                            else {
                                needed_metals[metal]++;
                            }
                        }
                    }
                    needed_metals[i] = 0;
                }
                else {
                    valid = false;
                    break;
                }
            }
        }

        if (!valid) {
            break;
        }

        vector<int> new_needed_metals;

        for (int i = 0; i < needed_metals.size(); i++) {
            if (needed_metals[i] != 0) {
                new_needed_metals.push_back(needed_metals[i]);
            }
        }
        
        if (new_needed_metals.size() == 0) {
            metals[N]++;
        }
        else {
            break;
        }
    }

    int N_metal_counter = metals[N];
    cout << N_metal_counter << "\n";

    return 0;
}