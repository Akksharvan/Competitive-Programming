#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int N, K;
    cin >> N >> K;

    string C;
    cin >> C;

    vector<char> P(N);
    for (char &p : P) p = '.';

    int LG = (-1) * (K) - 1;
    int LH = (-1) * (K) - 1;
    int PC = 0;

    int r = N - 1;

    for (int i = 0; i < N; i++) {
      if (C[i] == 'G' && abs(i - LG) > K) {
        if (i + K < r) {
          P[i + K] = 'G';
          LG = i + K;
          PC++;
        }
        else {
          P[r] = 'G';
          LG = r;
          PC++;
          r--;
        }
      }
      else if (C[i] == 'H' && abs(i - LH) > K) {
        if (i + K < r) {
          P[i + K] = 'H';
          LH = i + K;
          PC++;
        }
        else {
          P[r] = 'H';
          LH = r;
          PC++;
          r--;
        }
      }
    }

    cout << PC << nl;
    for (char &p : P) cout << p;
    cout << nl;
  }

  return 0;
}