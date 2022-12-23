#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    vector<bool> B;

    for (int i = 0; i < N - 1; i += 2) {
        if (S[i] == S[i + 1]) {
            continue;
        }

        if (S[i] == 'G') {
            B.push_back(false);
        }
        else {
            B.push_back(true);
        }
    }


    int reversals = 0;
    reverse(B.begin(), B.end());

    for (const bool& b : B) {
        if (b && reversals % 2 == 1) {
            reversals++;
        }
        else if (!(b) && reversals % 2 == 0) {
            reversals++;
        }
    }

    cout << reversals << "\n";

    return 0;
}