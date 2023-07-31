#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int GCD = gcd(A[0], A[0]);
        for (int i = 1; i < N; i++) {
            GCD = gcd(GCD, A[i]);
        }

        for (int i = 0; i < N; i++) {
            int Y = A[i] / GCD;
            cout << Y << spc;
        }

        cout << nl;
    }
    
	return 0;
}