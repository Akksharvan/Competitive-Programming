#include <iostream>
#include <algorithm>

#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> cubes(4);
    for (int i = 0; i < 4; i++) {
        cin >> cubes[i];
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        vector<int> permutation = {0, 1, 2, 3};
        bool spellable = false;
        int word_size = s.length();

        do {
            bool good = true;

            for (int j = 0; j < word_size; j++) {
                bool valid = false;

                for (char c : cubes[permutation[j]]) {
                    if (c == s[j]) {
                        valid = true;
                        break;
                    }
                }

                if (!valid) {
                    good = false;
                    break;
                }
            }

            if (good) {
                spellable = true;
                break;
            }
        } while (next_permutation(permutation.begin(), permutation.end()));

        if (spellable) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}