#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> E;
	DSU (int N) { E = vector<int> (N, -1); }
    
	int G (int x) { return E[x] < 0 ? x : E[x] = G(E[x]); }
	bool S (int a, int b) { return G(a) == G(b); }

	int SZ (int x) { return -E[G(x)]; }
	bool U (int x, int y) {
		x = G(x), y = G(y);
		if (x == y) return 0;
		
        if (E[x] > E[y]) swap(x, y);
		E[x] += E[y]; E[y] = x;
		
        return 1;
	}
};

bool F (vector<int> &A) {
    DSU D((int) size(A));
    vector<int> B(32, -1);

    for (int b = 0; b < 32; b++) {
        for (int i = 0; i < (int) size(A); i++) {
            if (!(A[i] & (1 << b))) continue;
            B[b] = i; break;
        }
    }

    for (int b = 0; b < 32; b++) {
        for (int i = 0; i < (int) size(A); i++) {
            if (!(A[i] & (1 << b))) continue;
            D.U(i, B[b]); continue;
        }
    }

    if (D.SZ(0) == (int) size(A)) return 1;
    else return 0;
}

void G (vector<int> &A) {
    for (int &i : A) cout << i << " ";
}

void solve() {
    int N, R = 0; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    for (int &i : A) {
        if (i > 0) continue;
        i += 1; R += 1;
    }

    if (F(A)) {
        cout << R << "\n";
        G(A); cout << "\n"; return;
    }

    for (int i = 0; i < N; i++) {
        vector<int> B = A;
        B[i] += 1;

        if (F(B)) {
            cout << (R + 1) << "\n";
            G(B); cout << "\n"; return;
        }

        if (B[i] > 1) B[i] -= 2;
        else continue;

        if (F(B)) {
            cout << (R + 1) << "\n";
            G(B); cout << "\n"; return;
        }
    }

    vector<int> B; int C = 0;
    for (int i = 0; i < N; i++) {
        if ((A[i] & -A[i]) > C) { B.clear(); B.push_back(i); C = (A[i] & -A[i]); }
        else if ((A[i] & -A[i]) == C) B.push_back(i);
    }

    A[B[0]] -= 1;
    A[B[1]] += 1;

    cout << (R + 2) << "\n";
    G(A); cout << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}