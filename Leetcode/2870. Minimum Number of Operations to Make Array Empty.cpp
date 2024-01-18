static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int minOperations(vector<int> &A) {
        unordered_map<int, int> B; for (int &i : A) B[i]++;
        int R = 0; for (const pair<int, int> &i : B) {
            if (i.second == 1) return -1;
            else R += (i.second / 3) + ((i.second % 3) != 0);
        }

        return R;
    }
};