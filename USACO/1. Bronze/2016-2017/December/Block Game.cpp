#include <iostream>
#include <cstdio>
#include <array>
#include <string>

using namespace std;
const char a = 'a';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N;
    array<int, 26> alphabetBlocks{};

    cin >> N;

    for (int i = 0; i < N; i++) {
        string firstWord;
        string secondWord;

        array<int, 26> alphabetCounterOne{};
        array<int, 26> alphabetCounterTwo{};

        cin >> firstWord >> secondWord;

        for (char character : firstWord) {
            int letter = character - a;
            alphabetCounterOne[letter]++;
        }

        for (char character : secondWord) {
            int letter = character - a;
            alphabetCounterTwo[letter]++;
        }

        for (int j = 0; j < 26; j++) {
            alphabetBlocks[j] += max(alphabetCounterOne[j], alphabetCounterTwo[j]);
        }
    }

    for (int counter : alphabetBlocks) {
        cout << counter << endl;
    }

    return 0;
}