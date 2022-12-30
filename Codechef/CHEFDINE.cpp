#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N);
        for (int &a : A) cin >> a;
        
        vector<int> B(N);
        for (int &b : B) cin >> b;
        
        map<int, int> C;
        for (int i = 0; i < N; i++) {
            if (C.count(A[i])) C[A[i]] = min(C[A[i]], B[i]);
            else C[A[i]] = B[i];
        }
        
        vector<int> D;
        for (const pair<int, int> &c : C) D.push_back(c.second);
        
        long long int t = 0;
        sort(D.begin(), D.end());
        
        if ((int) D.size() >= K) {
            for (int i = 0; i < K; i++) t += D[i];
            cout << t << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}