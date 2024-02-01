#include <bits/stdc++.h>
using namespace std;

bool F (string &S) {
    for (char &c : S) if ((isalpha(c) && c != 'u' && c != 'm') || ((isdigit(c) || c == ' '))) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string R, S; while (cin >> S) {
        if (!F(S)) continue;

        for (char &c : S) {
            if (c == 'u') R += '1';
            else if (c == 'm') R += '0';
        }
    }

    string W;
    for (int i = 0; i < size(R); i += 7) {
        int X = 0;
        for (int j = i; j < i + 7; j++) X = X * 2 + (R[j] - '0');

        W += (char) X;
    }

    cout << W << "\n";

    return 0;
}