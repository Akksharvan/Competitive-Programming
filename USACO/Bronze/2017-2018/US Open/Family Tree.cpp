#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; string S1, S2; cin >> N >> S1 >> S2;

    map<string, string> A; while (N--) { string U, V; cin >> U >> V; A[V] = U; }
    if (A.count(S1) && A.count(S2) && A[S1] == A[S2]) { cout << "SIBLINGS" << "\n"; return 0; }

    vector<string> B, C; string S3 = S1, S4 = S2;
    B.push_back(S1); C.push_back(S2);

    while (A.count(S3)) { B.push_back(A[S3]); S3 = A[S3]; }
    while (A.count(S4)) { C.push_back(A[S4]); S4 = A[S4]; }

    for (int i = 0; i < size(B); i++) for (int j = 0; j < size(C); j++) {
        if (B[i] != C[j]) continue;

        if (i == 0 && j == 1) { cout << S1 << " is the mother of " << S2 << "\n"; return 0; }
        if (i == 0 && j == 2) { cout << S1 << " is the grand-mother of " << S2 << "\n"; return 0; }

        if (i == 0 && j > 2) { cout << S1 << " is the "; for (int k = 0; k < j - 2; k++) cout << "great-"; cout << "grand-mother of " << S2 << "\n"; return 0; }
        if (i == 1 && j != 0) { cout << S1 << " is the "; for (int k = 0; k < j - 2; k++) cout << "great-"; cout << "aunt of " << S2 << "\n"; return 0;}

        if (j == 0 && i == 1) { cout << S2 << " is the mother of " << S1 << "\n"; return 0; }
        if (j == 0 && i == 2) { cout << S2 << " is the grand-mother of " << S1 << "\n"; return 0; }
        
        if (j == 0 && i > 2) { cout << S2 << " is the "; for (int k = 0; k < i - 2; k++) cout << "great-"; cout << "grand-mother of " << S1 << "\n"; return 0; }
        if (j == 1 && i != 0) { cout << S2 << " is the "; for (int k = 0; k < i - 2; k++) cout << "great-"; cout << "aunt of " << S1 << "\n"; return 0;}

        cout << "COUSINS" << "\n"; return 0;
    }

    cout << "NOT RELATED" << "\n";
    return 0;
}