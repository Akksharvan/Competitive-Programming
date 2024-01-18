static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = size(paths);
        map<string, int> freq;
        for (int i = 0; i < n; i++) freq[paths[i][0]]++; 
        for (int i = 0; i < n; i++) if (freq[paths[i][1]] == 0) return paths[i][1];
        return "";
    }
};