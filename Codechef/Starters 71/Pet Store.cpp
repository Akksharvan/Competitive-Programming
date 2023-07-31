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
        
        map<int, int> A;
        for (int i = 0; i < N; i++)  {
            int a;
            cin >> a;
            A[a]++;
        }

        bool good = 1;
        for (const pair<int, int> &a : A) if (a.second % 2) good = 0;
        cout << ((good) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}