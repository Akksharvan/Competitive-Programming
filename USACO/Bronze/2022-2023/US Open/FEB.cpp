#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; string S; cin >> N >> S;
    vector<int> A; for (int i = 0; i < N; i++) if (S[i] != 'F') A.push_back(i);

    int R1 = 0, R2 = 0, R3 = 0, R4 = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'F') R3++;
        else break;
    }

    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == 'F') R4++;
        else break;
    }

    if (R3 + R4 >= N) {
        cout << N << "\n";
        for (int i = 0; i < N; i++) cout << i << "\n";
        
        return 0;
    }

    N = size(A);
    
    for (int i = 1; i < N; i++) {
        if (S[A[i - 1]] == S[A[i]]) R1 += ((A[i] - A[i - 1] & 1)), R2 += (A[i] - A[i - 1]);
        else if (((A[i] - A[i - 1]) & 1)) R2 += (A[i] - A[i - 1] - 1);
        else R1++, R2 += (A[i] - A[i - 1] - 1);
    }

    if (R3 || R4) {
        int K = R2 + (R3 + R4) - R1 + 1; cout << K << "\n";
        for (int i = R1; i <= R2 + (R3 + R4); i++) cout << i << "\n";
    }
    else {
        int K = (R2 - R1) / 2 + 1; cout << K << "\n";
        for (int i = R1; i <= R2; i += 2) cout << i << "\n";
    }

    return 0;
}