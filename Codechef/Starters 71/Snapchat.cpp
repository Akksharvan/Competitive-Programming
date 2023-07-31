#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        for (int &a : A) cin >> a;
        
        vector<int> B(N);
        for (int &b : B) cin >> b;
        
        int ms = 0, cs = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] && B[i]) cs++;
            else ms = max(ms, cs), cs = 0;
        }
        
        ms = max(ms, cs);
        cout << ms << "\n";
    }
    
    return 0;
}