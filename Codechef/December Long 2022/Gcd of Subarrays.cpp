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
        long long int N, K;
        cin >> N >> K;

        long long int S = (((N * N) + N) / 2) - 1;
        if (K <= S) {
            cout << -1 << nl;
        }
        else {
            for (int i = 0; i < N - 1; i++) {
                cout << 1 << spc;
            }

            cout << K - S << spc;
        }

        cout << nl;
    }
    
	return 0;
}