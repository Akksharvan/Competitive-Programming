static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    long long MOD = 1e9 + 7;
    int findPaths (int N, int M, int K, int I, int J) {
        vector<vector<vector<int>>> DP(N + 2, vector<vector<int>> (M + 2, vector<int> (K + 1)));
        vector<vector<vector<bool>>> V(N + 2, vector<vector<bool>> (M + 2, vector<bool> (K + 1)));

        DP[I + 1][J + 1][0] = 1; queue<array<int, 3>> A; A.push({I + 1, J + 1, 0});

        while (!A.empty()) {
            array<int, 3> B = A.front(); A.pop();
            if (B[2] == K || V[B[0]][B[1]][B[2]]) continue;

            if (B[0] == 0 || B[0] == N + 1) continue;
            if (B[1] == 0 || B[1] == M + 1) continue;

            V[B[0]][B[1]][B[2]] = 1;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) + abs(j) != 1) continue;
                    A.push({B[0] + i, B[1] + j, B[2] + 1});

                    DP[B[0] + i][B[1] + j][B[2] + 1] += DP[B[0]][B[1]][B[2]];
                    DP[B[0] + i][B[1] + j][B[2] + 1] %= MOD;
                }
            }
        }

        long long R = 0;

        for (int i = 0; i <= N + 1; i += N + 1) {
            for (int j = 1; j <= M; j++) {
                for (int k = 1; k <= K; k++) {
                    R += DP[i][j][k];
                    R %= MOD;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M + 1; j += M + 1) {
                for (int k = 1; k <= K; k++) {
                    R += DP[i][j][k];
                    R %= MOD;
                }
            }
        }

        return R;
    }
};