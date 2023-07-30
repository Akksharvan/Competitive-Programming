#include <bits/stdc++.h>
using namespace std;
 
array<array<bool, 8>, 8> B;
vector<int> P{0, 1, 2, 3, 4, 5, 6, 7};
 
bool foo () {
    for (int i = 0; i < 8; i++) {
        if (!B[i][P[i]]) return 0;
    }
 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == j) continue;
            if (abs(i - j) == abs(P[i] - P[j])) return 0;
        }
    }
 
    return 1;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c; cin >> c;
            B[i][j] = (c == '.' ? 1 : 0);
        }
    }
 
    int R = 0;
    do { R += foo(); } while (next_permutation(begin(P), end(P)));
 
    cout << R << "\n";
    return 0;
}