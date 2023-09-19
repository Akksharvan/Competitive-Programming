#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool highFreq(string sub_string, string main_string) {
    bool high_freq = false;
    int found = main_string.find(sub_string);

    if (found >= 0) {
        int found_two = main_string.find(sub_string, found + 1);
        if (found_two >= 0) {
            high_freq = true;
        }
    }

    return high_freq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N;
    cin >> N;

    string mailbox_sequence;
    cin >> mailbox_sequence;

    int K = N;

    for (int i = 1; i < K; i++) {
        int valid = true;

        for (int j = 0; j < N - i; j++) {
            string sub_string = mailbox_sequence.substr(j, i);

            if (highFreq(sub_string, mailbox_sequence)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            K = i;
            break;
        }
    }

    cout << K << "\n";

    return 0;
}