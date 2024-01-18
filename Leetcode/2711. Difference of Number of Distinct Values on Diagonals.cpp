class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> answer(n, vector<int> (m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                set<int> tL, bR;
                
                for (int k = min(i, j); k > 0; k--) tL.insert(grid[i - k][j - k]);
                for (int k = 1; k < min(n, m); k++) {
                    if (i + k >= n || j + k >= m) break;
                    else bR.insert(grid[i + k][j + k]);
                }
                
                int l = (int) tL.size(), r = (int) bR.size();
                answer[i][j] = abs(l - r);
            }
        }
        
        return answer;
    }
};