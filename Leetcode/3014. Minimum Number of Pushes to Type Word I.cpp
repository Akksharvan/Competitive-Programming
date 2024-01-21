class Solution {
public:
    int minimumPushes (string S) {
        vector<int> A(26); int R = 0;
        for (char &c : S) A[c - 97]++;
        
        sort(rbegin(A), rend(A));
        for (int i = 0; i < 26; i++) R += ((i / 8) + 1) * A[i];
        
        return R;
    }
};