#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S, P; cin >> S >> P;
    set<string> A; A.insert(P);

    for (char i = '0'; i <= '9'; i++) {
        A.insert(P + i);
        A.insert(i + P);
    }

    string R;
    for (char &c : P) {
        if (isdigit(c)) R += c;
        else if (tolower(c) == c) R += toupper(c);
        else R += tolower(c);
    }

    A.insert(R);

    if (A.count(S)) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return 0;
}