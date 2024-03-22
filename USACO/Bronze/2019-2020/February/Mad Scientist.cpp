#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; string S1, S2;
    cin >> N >> S1 >> S2;

    vector<bool> A(N), B(N);
    for (int i = 0; i < N; i++) A[i] = (S1[i] == 'G'), B[i] = (S2[i] == 'G');

    int R = 0; for (int i = 0; i < N; i++) {
        if (A[i] == B[i]) continue; R++;
        while (i < N && A[i] != B[i]) i++; i--;
    }

    cout << R << "\n";
    return 0;
}