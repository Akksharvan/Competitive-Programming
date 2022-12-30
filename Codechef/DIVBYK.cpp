#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<int, (int) 1e6 + 1> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 2; i <= (int) 1e6; i++) {
        if (mp[i] == 0) {
            for (int j = i; j <= (int) 1e6; j += i) {
                mp[j] = i;
            }
        }
    }
    
    int T;
    cin >> T;
    
    while (T--) {
        int A, K;
        cin >> A >> K;

        vector<int> a(A);
        for (int i = 0; i < A; i++) {
            cin >> a[i];
        }

        map<int, int> apfs;
        map<int, int> kpfs;

        for (int &x : a) {
            while (x != 1) {
                int p = mp[x];
                x /= p;
                apfs[p]++;
            }
        }

        while (K != 1) {
            int p = mp[K];
            K /= p;
            kpfs[p]++;
        }

        bool divisible = true;
        for (const pair<int, int> &pfc : kpfs) {
            if (apfs[pfc.first] < pfc.second) {
                divisible = false;
                break;
            }
        }
        
        if (divisible) {
            cout << "YES" << nl;
        }
        else {
            cout << "NO" << nl;
        }
    }
    
	return 0;
}