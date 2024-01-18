class Solution {
public:
    int maxFrequencyElements(vector<int> &A) {
        map<int, int> B; for (int &i : A) B[i]++;
        int R1 = 0, R2 = 0; for (const pair<int, int> &i : B) {
            if (i.second > R2) R2 = i.second, R1 = 1;
            else if (i.second == R2) R1++;
        }
            
        return (R1 * R2);
    }
};